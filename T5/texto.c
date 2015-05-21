


/*
 * texto.c
 * Funções para implementação de editor de texto.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014, 2015 João V. F. Lima, UFSM
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "texto.h"
#include "tela.h"
#include "memo.h"
#include "lista.h"

/* estados para o campo texto */
enum { nada, editando } estado;

texto_t* texto_inicia()
{
	texto_t* t = (texto_t*)memo_aloca(sizeof(texto_t));
	t->linhas = lista_cria();
	tamanho_t tam = { 600, 400 };	/* tamanho da tela */

	tela_inicializa(&t->tela, tam, "Editor teste");
	tela_limpa(&t->tela);

	t->nlin = 0;
	t->lincur = 0;
	t->colcur = 0;
	t->lin1 = 0;
	t->col1 = 0;

	/* inicialize aqui quaisquer outras estruturas, como a lista de linhas */
	
	return t;
}

void texto_destroi(texto_t* txt)
{
	lista_destroi(txt->linhas);
	tela_limpa(&txt->tela);
	tela_finaliza(&txt->tela);
	memo_libera(txt->linhas);
	memo_libera(txt);
}

tela_t* texto_tela(texto_t* txt)
{
	assert( txt != NULL );
	return &txt->tela;
}

void texto_desenha_cursor_tela(texto_t *txt)
{
	cor_t preto = {0.0, 0.0, 0.0};
	tamanho_t tt;
	ponto_t pt1, pt2;
	int i;
	elem_t* aux = txt->linhas->primeiro;
	for (i=0; i<txt->lincur;i++)
		aux = aux->prox;
	//printf ("txt->colcur: %d\n",txt->colcur);
	/* ATENÇÃO: ajustar aqui o tamanho do texto onde o cursor está.
	 * Isso é necessário pois cada caractere pode ter tamanhos diferentes
	 * na horizontal.  */
#if 1
	{
		char subtexto[60];
		strncpy(subtexto, aux->lista, txt->colcur*sizeof(char));
		subtexto[txt->colcur] = '\0';
		tt = tela_tamanho_texto(&txt->tela, subtexto);
	}
#endif
#if 0
	{
		char* subtexto = "A\0" ;
		tt = tela_tamanho_texto(&txt->tela, subtexto);
	}
#endif
	/* posicao x (horizontal) do cursor */
	pt1.x = tt.larg + 1;
	//pt1.x = tt.larg*txt->colcur + 1;
	/* posicao y (vertical) do cursor */
	pt1.y = txt->lincur * tt.alt;
	  pt2.x = pt1.x;
	pt2.y = pt1.y + tt.alt;
	tela_cor(&txt->tela, preto);
	tela_linha(&txt->tela, pt1, pt2);
}





void texto_gruda_linha(texto_t *txt){
  
    elem_t* aux = txt->linhas->primeiro;
    int i;
    for (i=0;i<txt->lincur;i++)
	    aux = aux->prox;
    if (txt->colcur == 0 && txt->lincur == 0)
	      return;
    else if (txt->colcur == 0 && strcmp(aux->lista, "\0") == 0){
	      lista_remove(txt->linhas,txt->lincur);
	      txt->colcur = strlen(aux->ant->lista);
	      txt->lincur--;
	      return;
	}
    else {
	      char* aux1 = memo_aloca(sizeof(char)*strlen(aux->lista));
	      strcpy(aux1,aux->lista);
	      aux1[strlen(aux1)] = '\0';
	      char* aux2;
	      if (strcmp(aux->ant->lista, "\0") != 0){
			     aux2 = memo_aloca(sizeof(char)*(strlen(aux->lista) + strlen(aux->ant->lista)));
			     strcpy(aux2,aux->ant->lista);
			     aux2[strlen(aux2)] = '\0';
	      }
	      else{
			  lista_remove(txt->linhas, txt->lincur - 1);
			  txt->lincur--;
			  return;
	      }
	      strcat(aux2,aux1);
	      aux2[strlen(aux2)] = '\0';
	      aux->ant->lista = memo_realoca(aux->ant->lista,sizeof(char)*strlen(aux2));
	      strcpy(aux->ant->lista,aux2);
	      aux->ant->lista[strlen(aux->ant->lista)] = '\0';
	      lista_remove(txt->linhas,txt->lincur);
	      lista_mostra(txt->linhas);
	      txt->colcur = strlen(aux->ant->lista);
	      txt->lincur--;
	      memo_libera(aux2);
	      memo_libera(aux1);
    }
  
}

//o que da enter
void texto_quebra_linha(texto_t *txt){
      
      elem_t* aux = txt->linhas->primeiro;
      int i, j;
      char* aux2, *aux3;
      for (i=0; i<txt->lincur;i++)
	    aux = aux->prox;
      if (strlen(aux->lista) == txt->colcur){ //se estiver na ultima posição
	  lista_insere(txt->linhas,"\0",i+1);
	  txt->colcur = 0;
	  txt->lincur++;
      }
      else if (aux->prox == NULL){
	    aux2 = memo_aloca(sizeof(char)* (txt->colcur + 1));
	    strncpy(aux2,aux->lista,txt->colcur+1);
	    aux2[txt->colcur] = '\0';
	    aux3 = memo_aloca(sizeof(char) * (strlen(aux->lista) - txt->colcur));
	    for (i=0; i < strlen(aux->lista) - txt->colcur; i++)
		  aux3[i] = aux->lista[txt->colcur+i];
	    aux3[strlen(aux3)] = '\0';
	    aux->lista = memo_realoca(aux->lista,sizeof(char) * (txt->colcur + 1));
	    strcpy(aux->lista,aux2);
	    aux->lista[strlen(aux->lista)] = '\0';
	    lista_insere(txt->linhas,aux3,txt->linhas->n);
	    memo_libera(aux3);
	    memo_libera(aux2);
	    txt->colcur = 0;
	    txt->lincur++;
	    return;
      }
	
      else{
	int resto = strlen(aux->lista) - txt->colcur;
	aux2 = memo_aloca(sizeof(char) * resto);
	for (j=0; j< resto; j++)
		aux2[j] = aux->lista[txt->colcur + j];
	aux2[resto] = '\0';
	if (txt->colcur > 0)
	      aux->lista = memo_realoca(aux->lista, sizeof(char) * txt->colcur);
	else 
	      aux->lista = memo_realoca(aux->lista, sizeof(char) * 1);
	aux->lista[txt->colcur] = '\0';
	lista_insere(txt->linhas,aux2, txt->lincur+1);
	memo_libera(aux2);
      }
	      
}

void texto_insere_char(texto_t *txt, char c){
	//Ajeitando qual linha vai ser inserida
	elem_t* aux = txt->linhas->primeiro;
	char *aux2 = memo_aloca(sizeof(char)*1);
	aux2[0]='\0';
	int i;
	for (i=0;i<txt->lincur;i++)
		aux=aux->prox;	
	int resto = strlen(aux->lista)-(txt->colcur);
	char *aux1 = memo_aloca(sizeof(char)*(txt->colcur + 2));
	strncpy(aux1, aux->lista, txt->colcur);
	aux1[txt->colcur] = c;
	aux1[txt->colcur + 1] = '\0';
	if (resto > 0){
	      aux2 = memo_aloca(sizeof(char)*resto);
	      for (i=0; i<resto;i++)
		      aux2[i] = aux->lista[i + txt->colcur];
	      aux2[resto] = '\0';
	}
	aux = memo_realoca(aux,sizeof(char) * (strlen(aux->lista) + 1));
	aux->lista = strcat(aux1,aux2);
	aux->lista[strlen(aux->lista)] = '\0';
	memo_libera(aux2);
	txt->colcur++;
}


void texto_remove_char(texto_t* txt){
    elem_t* aux = txt->linhas->primeiro;
    int i;
    //saber conteudo da linha atual
    for (i=0; i<txt->lincur;i++)
	  aux=aux->prox;
    
    
    int resto = strlen(aux->lista) - txt->colcur;
    
    char *aux1 = memo_aloca(sizeof(char)*1);
    aux1[0] = '\0';	
    char *aux2 = memo_aloca(sizeof(char)*1);
    aux2[0] = '\0';
    
    //Se for primeira posicao da primeira linha: Transforma em vazio
    if (txt->colcur - 1 == 0 && strlen(aux->lista) == 1){
	  aux->lista = "\0";	
	  txt->colcur--;
    }
     
    else if (txt->colcur > 0){ 
	  if (txt->colcur - 1 > 0){
		  aux1 = memo_realoca(aux1,sizeof(char)*(txt->colcur - 1));	
		  strncpy(aux1,aux->lista, txt->colcur - 1);
		  aux1[txt->colcur-1] = '\0';
	  }
	  if (resto > 0){
		  aux2 = memo_realoca(aux2,sizeof(char)*resto);
		  for (i=0; i<resto;i++)
			  aux2[i] = aux->lista[i + txt->colcur];
		  aux2[resto] = '\0';
	  }  	
	  aux1 = memo_realoca(aux1, sizeof(char) * (strlen(aux->lista) - 1));
	  strcat(aux1,aux2);
	  aux->lista = memo_realoca(aux->lista, sizeof(char) * (strlen(aux1)));
	  strcpy(aux->lista,aux1);
	  aux->lista[strlen(aux->lista)] = '\0';
	  txt->colcur--;
    }
    else if (txt->colcur == 0){
	  texto_gruda_linha(txt);
	  }
	  
    memo_libera(aux1);
    memo_libera(aux2);  

}




void texto_desenha_tela(texto_t *txt)
{
	cor_t cor;
	tamanho_t tt;
	ponto_t pt;
	int i=0;
	/* limpa a tela. Comentar se ficar lento */
	tela_limpa(&txt->tela);
 	elem_t* aux = txt->linhas->primeiro;
	while (aux != NULL){
		tt = tela_tamanho_texto(&txt->tela, aux->lista);
		/* cores RGB da linha */
		cor.r = 0;
		cor.g = 0;
		cor.b = 0;
		/* calcula posicao da nova linha */
		pt.x = 1;
		pt.y = (i)*tt.alt + 1;
		/* muda cor e desenha linha */
		tela_cor(&txt->tela, cor);
		tela_texto(&txt->tela, pt, aux->lista);
		i++;
		aux = aux->prox;
}
	texto_desenha_cursor_tela(txt);
}

void texto_atualiza_tela(texto_t *txt)
{
	texto_desenha_tela(txt);
	tela_mostra(texto_tela(txt));
	tela_espera(30);
}

bool texto_processa_comandos(texto_t* txt, char** argv)
{
	int tecla = tela_tecla(texto_tela(txt));
	int modificador = tela_tecla_modificador(texto_tela(txt));
	/* apertou CRTL + Q ? */
	if( tecla == ALLEGRO_KEY_Q && (modificador & ALLEGRO_KEYMOD_CTRL) ) {
		printf("CTRL+Q SAIR\n");
		return false;
	}

	else if( tecla == ALLEGRO_KEY_S && (modificador & ALLEGRO_KEYMOD_CTRL) ) {
		printf("CTRL+S SALVAR e PARAR DE EDITAR\n");
		/* muda estado na variável para não editar */
		FILE* arq;
		int i;
		arq = fopen(argv[1],"w");
		printf ("teste!\n");
		if (arq == NULL){
			printf ("Erro na abertura do arquivo!");
			return NULL;
		 }
		else{
			elem_t* aux = txt->linhas->primeiro;
			do {
				fprintf (arq, "%s\n", aux->lista);
				printf ("Inseriu %s\n",aux->lista);
				aux = aux->prox;
				printf ("removeu\n");
			}while(aux != NULL); }
		fclose(arq);
		estado = nada;
		return true;
	}
	

	else if (estado == editando && (modificador & ALLEGRO_KEYMOD_SHIFT) && tecla >= ALLEGRO_KEY_A && tecla <= ALLEGRO_KEY_Z){
		texto_insere_char(txt,tecla+64);
	}
	else if(estado == editando && tecla >= ALLEGRO_KEY_A && tecla <= ALLEGRO_KEY_Z){
		texto_insere_char(txt,tecla+96);
	}
	else if (estado == editando && tecla >= ALLEGRO_KEY_0 && tecla <= ALLEGRO_KEY_9){
		texto_insere_char(txt,tecla+21);
	}
	else if (estado == editando && tecla == ALLEGRO_KEY_SPACE)
		texto_insere_char(txt,32);
	else if (estado == editando && tecla == ALLEGRO_KEY_BACKSPACE)
		texto_remove_char(txt);
	
	else if (estado == editando && tecla == ALLEGRO_KEY_ENTER)
		texto_quebra_linha(txt);
	else if (estado == editando && tecla == ALLEGRO_KEY_COMMA)
		texto_insere_char(txt,44);
	else if (estado == editando && tecla == ALLEGRO_KEY_QUOTE)
		texto_insere_char(txt,39);
	else if (estado == editando && tecla == ALLEGRO_KEY_FULLSTOP)
		texto_insere_char(txt,46);
	

	else if( tecla == ALLEGRO_KEY_E && (modificador & ALLEGRO_KEYMOD_CTRL) ) {
		printf("CTRL+E EDITAR\n");
		/* muda estado na variável para editando */
		estado = editando;
	}


	
	
	/* teclas direcionais 
		ALLEGRO_KEY_LEFT
		ALLEGRO_KEY_RIGHT
		ALLEGRO_KEY_UP
		ALLEGRO_KEY_DOWN
	*/


	if( tecla == ALLEGRO_KEY_LEFT )
		texto_move_esq(txt);
	if( tecla == ALLEGRO_KEY_RIGHT )
		texto_move_dir(txt);
	if( tecla == ALLEGRO_KEY_UP )
		texto_move_cima(txt);
	if( tecla == ALLEGRO_KEY_DOWN )
		texto_move_baixo(txt);	
	return true;
}

void texto_move_esq(texto_t *txt)
{
	/* ATENÇÃO: apenas exemplo. Mudar implementação */
	if (txt->colcur > 0)
		txt->colcur--;
}

void texto_move_dir(texto_t *txt)
{
	/* ATENÇÃO: apenas exemplo. Mudar implementação */
	elem_t* aux = txt->linhas->primeiro;
	int i;
	for (i = 0; i < txt->lincur;i++)
		aux = aux->prox;
	if (strlen(aux->lista) > txt->colcur) 
		txt->colcur++;
}

void texto_move_baixo(texto_t *txt)
{
	/* ATENÇÃO: apenas exemplo. Mudar implementação */

	if (txt->lincur < txt->linhas->n - 1)
		txt->lincur++;
}

void texto_move_cima(texto_t *txt)
{
	/* ATENÇÃO: apenas exemplo. Mudar implementação */
	elem_t* aux = txt->linhas->primeiro;
	if (txt->lincur > 0){
		int i;
		for (i=0; i<txt->lincur-1;i++)
		    aux = aux->prox;
		if (strcmp(aux->lista,"") == 0)
		    txt->colcur = 0;
		txt->lincur--;
	}
}

