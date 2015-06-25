#include <stdio.h>
#include <stdlib.h>


typedef struct lista{

	int i;
	struct lista_t* prox;

}lista_t;

lista_t* cria(){
	  lista_t* l = (lista_t*)malloc(sizeof(lista_t));
	  l = NULL;
	  return l;
}

void insere(lista_t* l, int i){
	
	lista_t* l2 = (lista_t*)malloc(sizeof(lista_t));
	l2->i = i;
	l2->prox = NULL;
	lista_t* aux = l;
	if (aux == NULL){
	     printf ("aqui\n");
	     l->prox = l2;
	     printf("sim\n");
	  
	}
	else{
	      while (aux->prox != NULL)
		  aux = aux->prox;
	      aux->prox = l2;}

}

int main (){
  
	lista_t* l = cria();
	insere(l,5);
	insere(l,4);
	while (l != NULL){
	      printf ("%d ",l->i);
	      l = l->prox;}
	
  
  
}