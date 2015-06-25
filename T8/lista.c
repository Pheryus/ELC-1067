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

void printa_lista(lista_t* l){
      vertice_t* v;
      lista_t* aux = l;
      while (aux != NULL){
	v = aux->vertice;
	printf ("Palavra:%s\n",v->nome);
	aux = aux->prox;
      }	
  
}

void printa_adj(lista_t* l){
  
      vertice_t* v;
      lista_t* aux = l;
      while (aux != NULL){
	
	    
	
	
      }
  
  
  
}