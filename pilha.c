#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

/*Define o tamanho da pilha e estrutura
#define MAXPILHA 50
typedef char elem_t;
typedef struct stack{
int topo;
elem_t item[MAXPILHA];
} Pilha; */


void cria_pilha(Pilha *ps) {
    ps->topo = -1;
}

/* Verifica se a pilha está vazia */
int pilha_vazia(Pilha *ps) {
    if(ps->topo==-1)
    {
    	return 1; //pilha esta vazia
	}
	else
	{
		return 0; //pilha tem elementos
	}
}

/* Verifica se a pilha está cheia */
int pilha_cheia(Pilha *ps) {
    if(ps->topo=MAXPILHA-1)
    {
    	return 1; //pilha esta cheia
	}
	else
	{
		return 0; //pilha nao esta cheia
	}
}

/* Adiciona um item na pilha */
void insere_pilha(Pilha *ps, char x) {
    if (ps->topo==MAXPILHA-1) 
	{
        printf("Pilha cheia");
        return;
    }
    ps->topo++;
    ps->item[ps->topo] = x;
}

/* Remove um item da pilha e retorna-o */
char remove_pilha(Pilha *ps) {
    if (ps->topo==-1) 
	{
        printf("Pilha vazia, não há elementos para remover\n");
        exit(1);
    }
    return ps->item[ps->topo--];
}

/* Retorna o último item da pilha (sem remover) */
char elem_topo(Pilha *ps) {
    if (ps->topo==-1) 
	{
        printf("Pilha vazia");
        exit(1);
    }
    return ps->item[ps->topo];
}

/* Remove todos os elementos da pilha */
void libera_pilha(Pilha *ps) {
    ps->topo = -1;
}
