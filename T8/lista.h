#ifndef _LIST_H_
#define _LIST_H_
#include "memo.h"

struct vertice_t;


typedef struct lista {
	struct vertice_t *vertice;
	struct lista_t *prox;
  
}lista_t;

/* Coloque aqui suas funções de lista para vértices */

lista_t* lista_cria();
lista_t* lista_insere(lista_t* l,struct vertice_t* v);
void lista_remove(lista_t* l);

#endif