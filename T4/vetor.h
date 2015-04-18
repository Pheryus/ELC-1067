#ifndef _VETOR_H_
#define _VETOR_H_
/*
 * vetor.h
 * TAD que implementa um vetor dinamico.
 */

#include <stdbool.h>
#include "carta.h"

/* definicao do tipo vetor */
typedef struct vetor vetor_t;

/* funções que permitem realizar operações sobre um vetor */

/* retorna um novo vetor, vazio */
vetor_t* vetor_cria(void);

/* destrói o vetor vet, que deverá estar vazio. */
void vetor_destroi(vetor_t* vet);

/* retorna o número de elementos no vetor vet. */
int vetor_numelem(vetor_t *vet);

/* insere uma carta no vetor vet, na posição indice.
 * se a carta já existe nessa posição, as cartas subsequentes avançam uma
 * posição.
 * se o vetor não tem mais espaço (cheio), utiliza realloc.
 */
void vetor_insere_carta(vetor_t *vet, int indice, carta c);

/* remove uma carta que estava na posição indice.
 * As cartas depois de indice recuam 1 posição à frente.
 * Retorna a carta original que estava na posição indice do vetor vet.
 */
carta vetor_remove_carta(vetor_t *vet, int indice);

/* retorna o dado na posição indice do vetor vet */
carta vetor_acessa_carta(vetor_t *vet, int indice);

/* retorna true se o vetor vet for válido */
bool vetor_valido(vetor_t *vet);

#endif
