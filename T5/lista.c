/*
 * lista.h
 * Funções de TAD lista duplamente encadeada.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014, 2015 João V. F. Lima, UFSM
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "lista.h"
#include "memo.h"	

/* implementa aqui sua estrutura lista_t duplamente encadeada */

lista_t* lista_cria(){
	lista_t* l = (lista_t*)memo_aloca(sizeof(lista_t));
	l->primeiro = NULL;
	l->ultimo = NULL;
	l->n = 0;
}

void lista_destroi(lista_t* l){
	//printf ("Tamanho lista: %d\n",l->n);
	while (l->n > 0){
		lista_remove(l,0);
			}
}

void lista_mostra(lista_t* l){
	elem_t* aux = l->primeiro;
	while (aux != NULL){
		printf ("%s\n",aux->lista);
		aux = aux->prox;}
}



void lista_insere(lista_t* l, char* s, int pos){
	
	int i;
	elem_t* novo = (elem_t*)memo_aloca(sizeof(elem_t)), *aux;
	novo->lista = memo_aloca(sizeof(char)*strlen(s));
	strcpy(novo->lista,s);
	novo->lista[strlen(s)] = '\0';
	if (l->n == NULL){
		novo->ant = NULL;
		novo->prox = NULL;
		l->primeiro = novo;
		l->ultimo = novo;
}
	else {
	      if (pos == 0){
		    novo->ant = NULL;
		    novo->prox = l->primeiro;
		    l->primeiro->ant = novo;
		    l->primeiro = novo;
	      }
	      
	      else if (pos == l->n){
		    novo->ant = l->ultimo;
		    l->ultimo->prox = novo;
		    l->ultimo = novo;
		    l->ultimo->prox = NULL; 
	      }
	      else {
		    aux = l->primeiro;
		    for (i=0; i<pos-1;i++){
			    aux = aux->prox;
		    }
		    novo->prox = aux->prox;
		    novo->ant = aux;
		    if (aux->prox == NULL){
			    l->ultimo = novo;
			   }
		    else{
			    aux->prox->ant = novo;
			    }
		    aux->prox = novo;
	      }
	    
	}
	l->n++;
}

#if 0



void lista_remove(lista_t* l, int pos){
	elem_t* elemento;
	if (l->n == 0){
		printf ("Erro! Lista vazia!\n");
		return;}
	elemento = l->primeiro;
	printf ("a\n");
	l->primeiro = l->primeiro->prox;
	printf ("b\n");
	if (l->primeiro == NULL){
		l->ultimo = NULL;
		printf ("c\n");
	}
	else{
		l->primeiro->ant = NULL;
		printf ("c\n");
	}
	memo_libera (elemento->lista);
	printf ("d\n");
	memo_libera (elemento);
	printf ("e\n");
	l->n--;
}
#endif

void lista_remove(lista_t* l, int pos){
      int i;
      elem_t* elem, *elem2;	
      if (l->n == 0)
	  return;
      if (pos == 0){ //remoção do primeiro elemento
	    elem = l->primeiro;
	    l->primeiro = l->primeiro->prox;
	    if (l->primeiro == NULL)
		  l->ultimo = NULL;
	    else
		  l->primeiro->ant = NULL;
      }else if (pos == l->n - 1){ //remoção ultimo elemento
	    elem = l->ultimo;
	    l->ultimo->ant->prox = NULL;
	    l->ultimo = l->ultimo->ant;
      }else{	
	    elem2 = l->primeiro;
	    for (i=0;i<pos;i++)
		   elem2 = elem2->prox;
	    elem = elem2;
	    elem2->ant->prox = elem2->prox;
	    elem2->prox->ant = elem2->ant;
      }
	char* elemento = elem->lista;
	if (strcmp(elem->lista, "") != 0)
	      memo_libera(elem->lista);
	memo_libera(elem);
	l->n--;
	return elemento;
}

int lista_tamanho (lista_t* l){
	return l->n;
}

