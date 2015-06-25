#include "vertice.h"
#include <string.h>

vertice_t* vinicializa (){
      
      vertice_t* v = memo_aloca(sizeof(vertice_t));
      v->adjacentes = lista_cria();
      v->nome = NULL;
      v->chave = NULL;
      return v;
}

vertice_t* vcria(vertice_t* v, char* ch, char* no){
  
      v = (vertice_t*)memo_aloca(sizeof(vertice_t));
      v->chave = memo_aloca(sizeof(char)*strlen(ch));
      strcpy(v->chave,ch);
      v->chave[strlen(v->chave)] = '\0';
      v->nome = memo_aloca(sizeof(char)*strlen(no));
      strcpy(v->nome,no);
      v->nome[strlen(v->nome)] = '\0';
      v->adjacentes = NULL;
      return v;
}
