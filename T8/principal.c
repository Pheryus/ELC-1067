#include "grafo.h"
#include "vertice.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char **argv){
	
	
	grafo_t* g = grafo_cria();
	
	lista_t* l = g->vertices;
	vertice_t* v = NULL;
	char aux[50], aux2[50];
	int arestas, vertices, loop;
	char c;
	int i;
	
	FILE* f = fopen(argv[1],"r");
	if (f == NULL){
		printf ("Erro de leitura do arquivo!\n");
		return;}
	else{
		 fscanf(f,"%d %d\n",&vertices, &arestas);
		 loop = vertices;
		 
		 while (loop){
			i = 0;
			c = fgetc(f);
			while (c != ' '){
			      aux[i] = c;
			      c = fgetc(f);
			      i++;}
			aux[i] = '\0';
			c = fgetc(f);
			i = 0;
			while (c != '\n'){
			      aux2[i] = c;
			      c = fgetc(f);
			      i++;}
			aux2[i] = '\0';
			v = vcria(v,aux,aux2);
			grafo_insere_vertice(g,v);
			
			loop--;
		 }
		 loop = arestas;
		 while(loop){
			fscanf(f,"%s %s", aux,aux2);
			printf ("inserindo aresta %s com %s\n",aux,aux2);
			grafo_insere_aresta(g,aux,aux2);
			loop--;
		 }
	}
	grafo_imprime(g);
  
}