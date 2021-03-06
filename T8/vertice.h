#ifndef _VERTICE_H_
#define _VERTICE_H_
#include "lista.h"
/*
 * vertice.h
 * Definição da estrutura de dados vertice_t de grafo.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 João V. F. Lima, UFSM
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

/* tipo vértice inserido na lista */
typedef struct vertice {
	char* chave; /* chave identificador */
	char* nome;   	       /* nome do vértice */
	lista_t* adjacentes; /* lista com os vértices adjacentes (vizinhos) */
} vertice_t;

vertice_t* vcria(vertice_t* v, char* ch, char* no);
vertice_t* vinicializa ();
void vlibera(vertice_t* v);

#endif /* _VERTICE_H_ */
