#ifndef _TELA_H_
#define _TELA_H_
/*
 * tela.h
 * Funções de tela com ncurses.
 */

#include <ncurses.h>

typedef struct {
    int y;
    int x;
} posicao;

typedef struct {
    int larg;
    int alt;
} tamanho;

typedef struct {
    int magico;
    tamanho tam_tela; /* tamanho total da tela */
} tela_t;
typedef tela_t *tela;

typedef enum {
    preto = 1,
    vermelho,
    verde,
    azul
} cor;

tela tela_cria(void);
void tela_destroi(tela t);

/* limpa a tela */
void tela_limpa(tela t);

/* posiciona o cursor em pos */
void tela_posiciona(tela t, posicao pos);

/* muda a cor */
void tela_muda_cor(tela t, cor c);

/* escreve o texto str na posicao do cursor */
void tela_escreve(tela t, char *str);

/* escreve o texto no espaco de larg caracteres, na pos atual do cursor */
void tela_escreve_centralizado(tela t, char *str, int larg);
void tela_escreve_esquerdado(tela t, char *str, int larg);
void tela_escreve_direitado(tela t, char *str, int larg);

/* atualiza a tela com as ultimas alteracoes (faz aparecer os tela_escreve) */
void tela_atualiza(tela t);

/* retorna a proxima tecla pressionada (man getch para os valores de retorno)*/
int tela_le(tela t);

/* le uma linha de caracteres (max tam caracteres) */
void tela_lelinha(tela t, char *s, int tam);
#endif                          /* _TELA_H_ */
