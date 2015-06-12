#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


pilha_t *pilha_cria(void){
  
      	pilha_t* pilha = (pilha_t*)memo_aloca(sizeof(pilha_t));
	pilha->topo = NULL;
	return pilha;
}

/* destrói a pilha p, que deverá estar vazia. */
void pilha_destroi(pilha_t* p){
	arv_t* no;
	while (!pilha_vazia(p))
		no = pilha_remove(p);
}

/* retorna true se a pilha p estiver vazia. */
bool pilha_vazia(pilha_t* p){
	return (p->topo == NULL);
}

/* insere o dado arv do tipo arv_t na pilha p */

void pilha_insere(pilha_t* pilha, arv_t* arv){

	elemento_t* elem = memo_aloca(sizeof(elemento_t));
	elem->arv = arv;
	if (pilha->topo == NULL){
		elem->prox = NULL;
		pilha->topo = elem;
	}
	else{
		elem->prox = pilha->topo;
		pilha->topo = elem;   
	}
}
  

/* retorna true se p for uma pilha válida */
bool pilha_valida(pilha_t* p){
  
	  elemento_t* aux = p->topo;
	  int cont;
	  while (aux != NULL){
		cont++;
		aux = aux->prox;
	  }
	  if (cont < 2)
	    return false;
	  return true;

}


/* remove e retorna o nó operador/operando no topo da pilha */
arv_t* pilha_remove(pilha_t* p){

	  elemento_t* aux = p->topo;
	  arv_t* arv = aux->arv;
	  aux = aux->prox;
	  memo_libera(p->topo);
	  p->topo = aux;	  
	  return arv;
}



