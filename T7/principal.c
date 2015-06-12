/*principal.c
 * Implementação de árvore de expressões aritméticas.
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

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "arv.h"
#include "pilha.h"
#include "memo.h"

int main(int argc, char **argv)
{
	/* exemplo simples de árvore */
	arv_t* operando, *operador;
	op_t soma, n1, n2;
	pilha_t* pilha;
	pilha = pilha_cria();
	
	char expressao[100];
	char* token; 
	int indice=0;
	
	printf ("Informe expressao:");  
	gets(expressao);
	token = strtok(expressao," ");
	while (token != NULL){
		  if (token[0] != '+' && token[0] != '-' && token[0] != '/' && token[0] != '*'){
			  n1.tipo = OPERANDO;
			  n1.u.operando = atof(token);
			  operando = arv_cria(n1);
			  pilha_insere(pilha,operando);	  
		  }
		  else {
			  soma.tipo = OPERADOR;
			  if (token[0] == '+')
				soma.u.operador = '+';
			  else if (token[0] == '-')
				soma.u.operador = '-';
			  else if (token[0] == '*')
				soma.u.operador = '*';
			  else if (token[0] == '/')
				soma.u.operador = '/';
			  if (pilha_valida(pilha)){
				operador = arv_cria(soma);
				arv_t* aux = pilha_remove(pilha);
				operador = arv_insere_direita(operador,aux);
				aux = pilha_remove(pilha);
				operador = arv_insere_esquerda(operador,aux);
				pilha_insere(pilha,operador);
			  }
			  
		  }
		  token = strtok(NULL, " ");
	  
	}
	
	printf ("-Printar arvore-\n");
	arv_imprime_em_ordem(pilha->topo->arv);
	printf ("\n");
	double result;
	result = calcula(pilha->topo->arv);
	printf ("Resultado: %.2f\n",result);
	arv_destroi(pilha->topo->arv);
	pilha_destroi( pilha );
	return 0;
	
}