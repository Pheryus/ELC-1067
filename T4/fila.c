/*
 * fila.c
 * TAD que implementa uma fila de elementos do tipo fila.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "memo.h"
#include "fila.h"
#include "vetor.h"

struct _fila {
	vetor_t* vet;
	int topo;
};

/* retorna uma nova fila, vazia */
fila fila_cria(void)
{
	struct _fila* f = (struct _fila*)memo_aloca(sizeof(struct _fila));
	assert(f != NULL);
	f->vet = vetor_cria();
	f->topo = 0;
	return f;
}

/* destrói a fila f, que deverá estar vazia. */
void fila_destroi(fila f)
{
	assert(f != NULL);
	vetor_destroi(f->vet);
	memo_libera(f);
}

/* retorna true se a fila f estiver vazia. */
bool fila_vazia(fila f)
{
	assert(f != NULL);
	return (f->topo <= 0);
}

/* insere o dado c do tipo carta na fila f */
void fila_insere_carta(fila f, carta c)
{
	assert((f != NULL) && (c != NULL));
	vetor_insere_carta(f->vet, f->topo, c);
	f->topo++;
}

/* remove e retorna a carta no topo da fila */
carta fila_remove_carta(fila f)
{
	assert((f != NULL)&&(f->topo > 0));
	carta c = vetor_remove_carta(f->vet, f->topo-1);
	f->topo--;
	return c;
}

/* retorna true se f for uma fila válida */
bool fila_valida(fila f)
{
	return ((f != NULL) && (f->vet != NULL));
}
