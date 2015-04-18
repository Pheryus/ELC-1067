#ifndef _JOGO_H_
#define _JOGO_H_
/*
 * jogo.h
 * TAD que implementa o jogo de cartas "solitaire".
 */

#include "carta.h"
#include "pilha.h"
#include "tela.h"

typedef struct {
    int magico;
    pilha monte;        // monte de cartas de onde se pode comprar
    pilha descartes;    // cartas ja abertas do monte; a de cima pode ser usada
    pilha ases[4];      // as 4 pilhas de cartas da saída
    pilha pilhas[7];    // as 7 pilhas principais do jogo
    tela tela;          // a tela onde sao desenhadas as cartas

    /* acrescente mais variáveis ao jogo, se necessário */
} jogo_t;
typedef jogo_t *jogo;

jogo jogo_cria(void);
void jogo_destroi(jogo);

bool jogo_valido(jogo sol);

/* acessores */
tela jogo_tela(jogo sol);
pilha jogo_monte(jogo sol);
pilha jogo_descartes(jogo sol);
pilha jogo_ases(jogo sol, int i);
pilha jogo_pilha(jogo sol, int i);

/* desenha a mesa do jogo */
void jogo_desenha(jogo);

/* acrescente mais funções ao jogo, se necessário */
#endif

