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

double calcula (arv_t* arv){
	double valor1, valor2;
	if (arv->dado.tipo == OPERANDO){
	      return arv->dado.u.operando;
	}
	else if (arv->dado.tipo == OPERADOR){
	      valor1 = calcula(arv->esq);
	      valor2 = calcula(arv->dir);
	      if (arv->dado.u.operador == '+'){
		      return valor2 + valor1;
	      }
	      else if (arv->dado.u.operador == '-')
		      return valor2 - valor1;
	      else if (arv->dado.u.operador == '*')
		      return valor1 * valor2;
	      else if (arv->dado.u.operador == '/')
		      return valor2/valor1;
	}
  
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
		printf ("%c ",arv->dado.u.operador);
	}
	else{
	      
		printf ("%.2f ",arv->dado.u.operando);
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
		printf ("%c ",arv->dado.u.operador);
	}
	else{
	      
		printf ("%.2f ",arv->dado.u.operando);
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
		printf ("%c ",arv->dado.u.operador);
	}
	else{
	      
		printf ("%.2f ",arv->dado.u.operando);
 	}  
}

/*  destroi toda a árvore */
arv_t* arv_destroi(arv_t* arv){
	  
	if (arv != NULL){
	      arv_destroi(arv->esq);
	      arv_destroi(arv->dir);
	      memo_libera(arv);
	}
	return NULL;
}


