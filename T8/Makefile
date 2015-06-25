	CC = gcc
CFLAGS := $(CFLAGS) -g -Wall 
LDFLAGS := $(LDFLAGS) -lm 

all: principal

principal.o: principal.c
lista.o: lista.c lista.h
memo.o: memo.c memo.h
grafo.o: grafo.c grafo.h
vertice.o: vertice.c vertice.h

principal: principal.o lista.o memo.o grafo.o vertice.o
	$(CC) $(CFLAGS) -o $@  $^ $(LDFLAGS)

clean:
	rm -f principal *.o
