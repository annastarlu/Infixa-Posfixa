//Anna Luiza Muller de Jesus - 237087
#include "pilha_estatica.h"
#include "lista_estatica-1.h"
#include <stdio.h>
#include <stdlib.h>

int prioridade(char op) //Analisa a prioridade do operador e classifica em categorias
{
    switch (op) 
	{
        case '+':
        case '-':
            return 1; //prioridade menor
        case '*':
        case '/':
            return 2; //prioridade maior
        default:
            return 0; //caso seja parenteses
    }
}


void posfixa(char *expressao, Lista *lista) // Função para converter expressão infixa para posfixa
{
    Pilha pl;
    int i;
    cria_pilha(&pl);
	
    for (i = 0; expressao[i] != '\0'; i++) 
	{
        if ((expressao[i] >= 'A' && expressao[i] <= 'Z')) // Se for um operando(letra), adiciona na lista
		{
            insere_fim(lista, expressao[i]);
        }
        else if (expressao[i] == '(') // Se for abertura de parenteses, empilha
		{
            insere_pilha(&pl, expressao[i]);
        }
        else if (expressao[i] == ')') // Se for fechamento de parenteses, desempilha até encontrar a abertura
		{
            while (pl.topo!=-1 && elem_topo(&pl) != '(') 
			{
                insere_fim(lista, remove_pilha(&pl));
            }
            remove_pilha(&pl); // Remove o '(' da pilha
        }
        else // Se for um operador(simbolo)
		{
            while (pl.topo!=-1 && prioridade(elem_topo(&pl)) >= prioridade(expressao[i])) //verifica prioridade
			{
                insere_fim(lista, remove_pilha(&pl)); //Se a priodade da expresao for menor ou igual ao topo da lista, desempilha o topo e empilha a expressao
            }
            insere_pilha(&pl, expressao[i]);
        }
    }

    while (pl.topo!=-1) //desempilha os operadores restantes 
	{
        insere_fim(lista, remove_pilha(&pl));
    }
}

int main() 
{
    char infixa[50];
    int i;
    printf("Digite a expressao infixa em maiusculo: "); //pergunta a expressao
    gets(infixa);
    Lista l_posfixa;
    cria(&l_posfixa);

    posfixa(infixa, &l_posfixa);

    printf("Expressão Posfixa: ");
    for (i = 0; i < l_posfixa.tam; i++) 
	{
        printf("%c", l_posfixa.vet[i]);
    }
}
