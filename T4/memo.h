#ifndef _MEMO_H_
#define _MEMO_H_
/*
 * memo.h
 * Funções para alocação de memória.
 */

/* Aloca 'tam' bytes de memória */
void* memo_aloca( size_t tam );

/* Realoca o ponteiro 'ptr' e retorna um novo vetor de tamanho 'tam' bytes */
void* memo_realoca( void* ptr, size_t tam );

/* Libera o ponteiro 'ptr' */
void memo_libera( void* ptr );

/* Imprime no terminal um relatório de alocações e liberações */
void memo_relatorio( void );

#endif /* _MEMO_H_ */
