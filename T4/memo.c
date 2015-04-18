/*
 * memo.c
 */

#include <stdio.h> // printf
#include <stdlib.h> // malloc/realloc/free

static long _memo_aloc = 0;
static long _memo_free = 0;
static size_t _memo_aloc_bytes = 0;
static size_t _memo_realoc_bytes = 0;

void* memo_aloca( size_t tam ){
	void *p = malloc( tam );
	if(p == NULL){
		printf("ERRO: não consegui alocar memória.\n");
		exit(-1);
	}
	_memo_aloc++;
	_memo_aloc_bytes += tam;
	return p;
}

void* memo_realoca( void* ptr, size_t tam ){
	void* p = realloc( ptr, tam );
	if(p == NULL){
		printf("ERRO: não consegui realocar memória.\n");
		exit(-1);
	}
	_memo_realoc_bytes += tam;
	return p;
}

void memo_libera( void* ptr ){
	if(ptr == NULL){
		printf("ERRO: ponteiro nulo!\n");
		exit(-1);
	}
	free(ptr);
	_memo_free++;
}

void memo_relatorio( void ){
	printf("\n** RELATÓRIO DE ALOCAÇÕES DE MEMÓRIA **\n");
	printf(" * Alocações  : %ld (total de %lu bytes)\n", _memo_aloc, _memo_aloc_bytes );
	printf(" * Liberações : %ld\n", _memo_free );
	printf(" * Realocações: %lu bytes\n", _memo_realoc_bytes );
	printf(" * SALDO      : %ld (alocações menos liberações)\n", _memo_aloc-_memo_free );
	printf("\n");
}

