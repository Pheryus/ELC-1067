#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
	int n;
	struct arvore* esq;
	struct arvore* dir;
  
}arvore_t;





pilha_t* pilha_cria(){
  
	pilha_t* pilha = (pilha_t*)malloc(sizeof(pilha_t));
	pilha->topo = NULL;
	return pilha;
}

arvore_t* arvore_cria(){
  
	arvore_t* arvore = (arvore_t*)malloc(sizeof(arvore_t));
	arvore->esq = NULL;
	arvore->dir = NULL;
	return arvore;
}

void arvore_insere (arvore_t* arv, int oper, arvore_t* esq, arvore_t* dir){
 
	  if (esq == NULL && dir == NULL){
		  arv->n = oper;
		  return;
	  }
  
  
  
  
}





void pilha_insere(pilha_t* pilha, char oper){

	elemento_t* p = (elemento_t*)malloc(sizeof(elemento_t));
	p->operador= dado;
	if (pilha->topo == NULL){
		p->prox = NULL;
		pilha->topo = p;
	}
	else{
		p->prox = pilha->topo;
		pilha->topo = p;
		//qelemento_t* aux = (elemento_t*)malloc(sizeof(elemento_t));
		//aux->operando = oper;
		//aux->prox = pilha->topo;
		//pilha->topo = aux;   
	}
}

void pilha_mostra (pilha_t* pilha){
      elemento_t* aux = pilha->topo;
      while (aux != NULL){
	      printf ("Pilha Topo: %c\n",aux->operador);
	      aux = aux->prox;
      }
}

int main (){
	pilha_t* pilha = pilha_cria();
	pilha_insere(pilha, 'h');
	pilha_insere(pilha, 'b');
	pilha_insere(pilha, 'c');
	
	arvore_t* arvore = arvore_cria();
	
	
	
}
