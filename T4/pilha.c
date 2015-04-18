/*
 * pilha.c
 * TAD que implementa uma fila de elementos do tipo pilha.
 */

#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "pilha.h"

struct _pilha {
	fila topo;
};

pilha pilha_cria(void){
	pilha p = (struct _pilha*)malloc(sizeof(struct _pilha));
	p->topo = fila_cria();
	return p;
}

void pilha_destroi(pilha p){
	fila_destroi(p->topo);
	free(p);
}

bool pilha_vazia(pilha p){
	return fila_vazia(p->topo);
}

void pilha_insere_carta(pilha p, carta c){
	fila_insere_carta(p->topo, c);
}

carta pilha_remove_carta(pilha p){
	return fila_remove_carta(p->topo);
}

bool pilha_valida(pilha p){
	return ((p != NULL) && (p->topo != NULL));
}
