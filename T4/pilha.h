#ifndef _PILHA_H_
#define _PILHA_H_
/*
 * pilha.h
 * TAD que implementa uma fila de elementos do tipo pilha.
 */

#include <stdbool.h>

#include "carta.h"

/* definicao do tipo pilha */
typedef struct _pilha* pilha;

/* funções que permitem realizar operações sobre uma pilha */
/* retorna uma nova pilha, vazia */
pilha pilha_cria(void);

/* destrói a pilha p, que deverá estar vazia. */
void pilha_destroi(pilha p);

/* retorna true se a pilha p estiver vazia. */
bool pilha_vazia(pilha p);

/* insere o dado c do tipo carta na pilha p */
void pilha_insere_carta(pilha p, carta c);

/* remove e retorna a carta no topo da pilha */
carta pilha_remove_carta(pilha p);

/* retorna true se p for uma pilha válida */
bool pilha_valida(pilha p);

#endif
