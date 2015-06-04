CC = gcc
CFLAGS := $(CFLAGS) -g -Wall 
LDFLAGS := $(LDFLAGS) -lm 

all: principal

principal.o: principal.c
pilha.o: pilha.c pilha.h
memo.o: memo.c memo.h
arv.o: arv.c arv.h

principal: principal.o pilha.o memo.o arv.o
	$(CC) $(CFLAGS) -o $@  $^ $(LDFLAGS)

clean:
	rm -f principal *.o
