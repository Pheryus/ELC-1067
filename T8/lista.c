#include "lista.h"
#include <string.h>
#include "vertice.h"


lista_t* lista_cria (){
	return NULL;
}

lista_t* lista_insere(lista_t* l, struct vertice_t* v){
	  lista_t* aux = (lista_t*)memo_aloca(sizeof(lista_t));
	  aux->vertice = v;
	  aux->prox = l;
	  return aux;
}

void lista_remove(lista_t* l){
  
	  if (l != NULL){
		  lista_remove(l->prox);
		  memo_libera(l);
    
	  }
}