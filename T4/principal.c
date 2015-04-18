/*
 * principal.c Esse programa testa as TADs implementadas para um jogo
 * solitário.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "memo.h"
#include "jogo.h"
#include "vetor.h"

void inicia_jogo(jogo solit){
    vetor_t* cartas = vetor_cria();
    vetor_t* fora_ordem = vetor_cria();
    srand( (unsigned)time(NULL) );
    int i, j;
    carta c;

    for(i=0; i<=3; i++){
        for(j=1; j<=13; j++){
            vetor_insere_carta(cartas, (i*13)+j-1, carta_cria(j,i));
        }
    }

    for(i=0; i < 52; i++){
        do{
            j = ((int)rand()%vetor_numelem(cartas));
            c = vetor_remove_carta(cartas, j);
        }while(c==NULL);
        vetor_insere_carta(fora_ordem, i, c);
    }

    for(i=0; i<7; i++){ //pilhas
        for(j=0; j<=i; j++){//cartas
            c = vetor_remove_carta(fora_ordem, 0);
            pilha_insere_carta(jogo_pilha(solit, i),c);
        }
        carta_abre(c); // esta no topo
    }

    for (i=0; i<24;i++){
        c = vetor_remove_carta(fora_ordem,0);
        pilha_insere_carta(jogo_monte(solit),c);
    }
    vetor_destroi(cartas);
    vetor_destroi(fora_ordem);
}

// Coloca a carta do topo do monte no descarte
void abrecartamonte(jogo solit){
	if (pilha_vazia(jogo_monte(solit))){
		printw ("Monte vazio!\n");
		return;
	}
    carta c = pilha_remove_carta(jogo_monte(solit));
    carta_abre(c);
    pilha_insere_carta(jogo_descartes(solit), c);
}

// Colocar cartas do monte de volta no baralho
void voltarMonte (jogo solit){
	if (!pilha_vazia(jogo_monte(solit)) || pilha_vazia(jogo_descartes(solit))){
		printf ("Monte nao esta vazio ou descarte esta vazio!\n");
		return;
	}
	while (!pilha_vazia(jogo_descartes(solit))){
		carta c = pilha_remove_carta(jogo_descartes(solit));
		carta_fecha (c);
		pilha_insere_carta(jogo_monte(solit), c);
	}
}

//move carta do descarte para uma das pilhas
void movedescarteparaPilha(jogo solit){
    int n;
    //n = (int)tela_le(jogo_tela(solit));
    scanf ("%d",&n);
    if (n > 6 || n < 0){
        printf ("valor invalido!\n");
        return;
    }
	jogo_desenha(solit);
    if (!pilha_vazia(jogo_descartes(solit))){
        carta c = pilha_remove_carta(jogo_descartes(solit));
        pilha_insere_carta(jogo_pilha(solit, n),c);
    }
    else
        printw ("descarte vazio\n");
}


//move todas cartas abertas de uma pilha para outra
void movepilhaapilha(jogo solit){
	int i, j;
	bool loop = true;
	printf ("Informe pilha 1:\n");
	scanf ("%d",&i);
	printf ("Informe pilha 2:\n");
	scanf ("%d",&j);
	if (i > 6 || i < 0 || j > 6 || j < 0 || j == i){
		printf ("Valores invalidos para pilha!\n");
		return;}
	do{
		carta c = pilha_remove_carta(jogo_pilha(solit, i));
		if (!carta_aberta(c)){
			loop = false;
			pilha_insere_carta(jogo_pilha(solit,i),c);}
		else
			pilha_insere_carta(jogo_pilha(solit,j),c);
	}while (loop);
}

void movedescarteas (jogo solit){
	int i;
	if (pilha_vazia(jogo_descartes(solit))){
		printf ("pilha vazia!\n");
		return;}
	
	printf ("Informe pilha as:\n");
	scanf ("%d",&i);
	if (i<0 || i>3){
		printf ("pilha invalida!\n");	
		return;}
	carta c = pilha_remove_carta (jogo_descartes(solit));
	if (pilha_vazia(jogo_ases(solit, i))){
		if (carta_valor(c) == AS)
			pilha_insere_carta(jogo_ases(solit, i), c);    
		else
			pilha_insere_carta(jogo_descartes(solit),c); 
					}
	else {
		carta c2 = pilha_remove_carta(jogo_ases(solit,i));
		if (carta_naipe(c2) == carta_naipe(c) && carta_valor(c) - carta_valor(c2) == 1)
			pilha_insere_carta(jogo_ases(solit,i),c);
		else{
			pilha_insere_carta(jogo_descartes(solit),c); 
			pilha_insere_carta(jogo_ases(solit,i),c2);}
	    }
}

void encerraJogo(jogo solit){
    jogo_destroi(solit);
    memo_relatorio();
    exit(0);
}

void testeparaganharjogo (jogo solit){
	if (pilha_vazia(jogo_descartes(solit)) && pilha_vazia(jogo_monte(solit)) && pilha_vazia(jogo_pilha(solit,0)) && pilha_vazia(jogo_pilha(solit,1)) && pilha_vazia(jogo_pilha(solit,2)) && pilha_vazia(jogo_pilha(solit,3)) && pilha_vazia(jogo_pilha(solit,4)) && pilha_vazia(jogo_pilha(solit,5)) && pilha_vazia(jogo_pilha(solit,6))){
	tela_limpa(jogo_tela(solit));
	printf ("Voce ganhou o jogo!!!!");
	encerraJogo(solit);}
}


void movepilhaases (jogo solit){
	int i, j;
	printf ("Informe pilha a ser retirado carta:\n");
	scanf ("%d",&i);
	if(i<0 || i > 6){
		printf ("pilha invalida!\n");
		return ;}
	printf ("Informe pilha do ases:\n");
	scanf ("%d",&j);
	if (j < 0 || j > 3){
		printf ("pilha invalida!\n");
		return;}
	if (pilha_vazia(jogo_pilha(solit,i))){
		printf ("pilha vazia!\n");
		return;}
	carta c = pilha_remove_carta(jogo_pilha(solit,i));
	if (pilha_vazia(jogo_ases(solit, i))){
		if (carta_valor(c) == AS)
			pilha_insere_carta(jogo_ases(solit, i), c);    
		else
			pilha_insere_carta(jogo_pilha(solit,i),c); 
					}
	else {
		carta c2 = pilha_remove_carta(jogo_ases(solit,i));
		if (carta_naipe(c2) == carta_naipe(c) && carta_valor(c) - carta_valor(c2) == 1)
			pilha_insere_carta(jogo_ases(solit,i),c);
		else{
			pilha_insere_carta(jogo_pilha(solit,i),c); 
			pilha_insere_carta(jogo_ases(solit,i),c2);}
	    }
}




int main(int argc, char **argv){
    char jogada;
	jogo solit;
	solit = jogo_cria();
    inicia_jogo(solit);
	bool jogo = true;

    while(jogo){
		jogo_desenha(solit);
		testeparaganharjogo(solit);	
		printw("\n -Escolha sua jogada-\n");
		printw ("\n As pilhas comecam a partir de 0\n");
		printw(" \n - Abrir uma carta do monte sobre o descarte: a\n");
		printw(" - Virar todas as cartas do descarte no monte vazio: v\n");
		printw(" - Move carta do descarte para uma pilha: m -> em seguida informe pilha e tecle ENTER\n");
		printw(" - Mover todas as cartas abertas de uma das 7 pilhas para outra: c -> em seguida informe pilha e tecle ENTER\n");
		printw (" - Move carta do descarte para a pilha de ases: s -> em seguida informe pilha de ases e tecle ENTER\n");
		printw (" - Move carta da pilha para a pilha de ases : z -> em seguida informe pilha, tecle ENTER, informe pilha de ases e tecle ENTER\n");
		printw(" - Encerrar jogo: x \n");
		printw("\n");
       		jogada = (char)tela_le(jogo_tela(solit));
		jogo_desenha(solit);
		printw ("Jogada:%c\n",jogada);
		if (jogada == 'a')
				abrecartamonte(solit);
		if (jogada == 'v')
				voltarMonte(solit);
		if (jogada == 'm')
				movedescarteparaPilha(solit);
		if (jogada == 'c')
				movepilhaapilha(solit);
		if (jogada == 's')
				movedescarteas(solit);
		if (jogada == 'x')
				encerraJogo(solit);
		if (jogada == 'z')
				movepilhaases(solit);
		}
	return 0;	
	}
