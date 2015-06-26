#include "grafo.h"
#include "memo.h"
#include <stdlib.h>
#include <string.h>

grafo_t* grafo_cria (){

      grafo_t* g = (grafo_t*)memo_aloca(sizeof(grafo_t));
      g->vertices = lista_cria();
      g->nvertices = 0;
      return g;
}

bool grafo_insere_vertice(grafo_t* g, vertice_t* v){
	lista_t* l = g->vertices;
	l = lista_insere(l,v);
	g->vertices = l;
	g->nvertices++;
}

vertice_t* grafo_busca_vertice(grafo_t* g, char* chave){
	  lista_t* l = g->vertices;
	  vertice_t* v;
	  while (l != NULL){
		  v = l->vertice;
		  if (strcmp(v->chave,chave) == 0){
			 return l->vertice;
		  }
		  else
			 l = l->prox;
	  }
	  return NULL;
}

bool grafo_insere_aresta(grafo_t* g, char* v1, char* v2){
	  lista_t* l = g->vertices;
	  vertice_t* aux1 = grafo_busca_vertice(g,v1);
	  //printf ("Conteudo: %s\n",aux1->nome);
	  vertice_t* aux2 = grafo_busca_vertice(g,v2);
	  //lista_t *adj1 = aux1->adjacentes, *adj2 = aux2->adjacentes;
	  aux1->adjacentes = lista_insere(aux1->adjacentes,aux2);
	  //printa_lista(adj1);
	  aux2->adjacentes = lista_insere(aux2->adjacentes,aux1);
	  //printa_lista(adj2);
	return true;
}

void grafo_imprime(grafo_t* g){
	int i;
	lista_t* l = g->vertices;
	vertice_t* v = l->vertice;
	lista_t* adj = v->adjacentes;
	for (i=0; i<g->nvertices;i++){
		v = l->vertice;
		adj = v->adjacentes;
		printf ("%s -> ",v->chave);
		while (adj != NULL){
		      v = adj->vertice;
		      printf ("%s ",v->chave);
		      adj = adj->prox;
		}
		printf("\n");
		l = l->prox;
	}
}

void grafo_destroi(grafo_t* g){
  
	lista_t* l = g->vertices;
	vertice_t* v;
	
	while (l != NULL){
		v = l->vertice;
		lista_remove(v->adjacentes);
		vlibera(v);
		l = l->prox;
	}
	lista_remove(g->vertices);
	memo_libera(g);
	
}