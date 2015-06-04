#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

/* criar uma árvore com o operador ou operando */
arv_t* arv_cria(op_t op){
	arv_t* p = (arv_t*)memo_aloca(sizeof(arv_t));
	p->dado = op;
	p->esq = NULL;
	p->dir = NULL;
	return p;
}

/* insere um novo dado na árvore a esquerda */
arv_t* arv_insere_esquerda(arv_t* arv, arv_t* op){
	arv->esq = op;
	return arv;
	
}

/* insere um novo dado na árvore a direita */
arv_t* arv_insere_direita(arv_t* arv, arv_t* op){
  
	arv->dir = op;
	return arv;
}

/* imprime a árvore em pré-ordem: raiz, esquerda, e direita */
void arv_imprime_pre_ordem(arv_t* arv){
	if (arv == NULL)
		return;
	if (arv->dado.tipo == OPERADOR){
		printf ("%c\n",arv->dado.u.operador);
	}
	else{
	      
		printf ("%f\n",arv->dado.u.operando);
	}
	arv_imprime_pre_ordem(arv->esq);
	arv_imprime_pre_ordem(arv->dir);
  
}

/* imprime a árvore em ordem: esquerda, raiz, e direita */
void arv_imprime_em_ordem(arv_t* arv){
  
	if (arv == NULL)
		return;
	arv_imprime_em_ordem(arv->esq);
	if (arv->dado.tipo == OPERADOR){
		printf ("%c\n",arv->dado.u.operador);
	}
	else{
	      
		printf ("%f\n",arv->dado.u.operando);
	}
	arv_imprime_em_ordem(arv->dir);	
}

/* imprime a árvore em pós-ordem: esquerda, direita, e raiz */
void arv_imprime_pos_ordem(arv_t* arv){
 
	if (arv == NULL)
		return;
	arv_imprime_pos_ordem(arv->esq);
	arv_imprime_pos_ordem(arv->dir);
	if (arv->dado.tipo == OPERADOR){
		printf ("%c\n",arv->dado.u.operador);
	}
	else{
	      
		printf ("%f\n",arv->dado.u.operando);
 	}  
}

/*  destroi toda a árvore */
void arv_destroi(arv_t* arv){
	  
	
  
  
}


