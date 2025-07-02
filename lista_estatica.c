//Anna Luiza Muller de Jesus - 237087
#include "lista_estatica-1.h"
#include <stdio.h>

/* Inicializa uma lista vazia */
void cria(Lista *p_l) {
    p_l->tam = 0;
}

/* Verifica se a lista está vazia */
int vazia(Lista *p_l) {
    return p_l->tam == 0;
}

/* Insere um elemento no início da lista */
void insere_inicio(Lista *p_l, int e) {
    int i;
	if (p_l->tam < MAX) {
        for (i = p_l->tam; i > 0; i--) {
            p_l->vet[i] = p_l->vet[i - 1];
        }
        p_l->vet[0] = e;
        p_l->tam++;
    }
}

/* Insere um elemento no final da lista */
void insere_fim(Lista *p_l, int e) {
    if (p_l->tam < MAX) {
        p_l->vet[p_l->tam] = e;
        p_l->tam++;
    }
}

/* Insere um elemento na lista de forma ordenada */
int insere_ordenado(Lista *p_l, int e) {
    int i, j;
	if (p_l->tam >= MAX) return 0;
    
    for (i = 0; i < p_l->tam; i++) {
        if (p_l->vet[i] == e) return 0;
        if (p_l->vet[i] > e) break;
    }
    
    for ( j = p_l->tam; j > i; j--) {
        p_l->vet[j] = p_l->vet[j - 1];
    }
    p_l->vet[i] = e;
    p_l->tam++;
    return 1;
}

/* Verifica se a lista está ordenada */
int ordenada(Lista *p_l) {
    int i;
	for (i = 1; i < p_l->tam; i++) {
        if (p_l->vet[i] < p_l->vet[i - 1]) {
            return 0;
        }
    }
    return 1;
}

/* Ordena a lista usando o algoritmo de inserção */
void ordena(Lista *p_l) {
    int i;
	for ( i = 1; i < p_l->tam; i++) {
        int chave = p_l->vet[i];
        int j = i - 1;
        while (j >= 0 && p_l->vet[j] > chave) {
            p_l->vet[j + 1] = p_l->vet[j];
            j--;
        }
        p_l->vet[j + 1] = chave;
    }
}

/* Remove o elemento no início da lista */
int remove_inicio(Lista *p_l, int *p_e) {
    int i;
	if (vazia(p_l)) return 0;
    
    *p_e = p_l->vet[0];
    for ( i = 0; i < p_l->tam - 1; i++) {
        p_l->vet[i] = p_l->vet[i + 1];
    }
    p_l->tam--;
    return 1;
}

/* Remove o elemento no final da lista */
int remove_fim(Lista *p_l, int *p_e) {
    if (vazia(p_l)) return 0;
    
    *p_e = p_l->vet[p_l->tam - 1];
    p_l->tam--;
    return 1;
}

/* Remove um valor específico da lista */
int remove_valor(Lista *p_l, int e) {
    int i,j;
    for (i = 0; i < p_l->tam; i++) {
        if (p_l->vet[i] == e) break;
    }
    if (i == p_l->tam) return 0;
    
    for (j = i; j < p_l->tam - 1; j++) {
        p_l->vet[j] = p_l->vet[j + 1];
    }
    p_l->tam--;
    return 1;
}

/* Inverte os elementos da lista */
void inverte(Lista *p_l) {
	int i, j;
    for ( i = 0, j = p_l->tam - 1; i < j; i++, j--) {
        int temp = p_l->vet[i];
        p_l->vet[i] = p_l->vet[j];
        p_l->vet[j] = temp;
    }
}

/* Remove todos os elementos da lista */
void libera(Lista *p_l) {
    p_l->tam = 0;
}

/* Exibe o conteúdo da lista */
void exibe(Lista *p_l) {
    int i;
	for (i = 0; i < p_l->tam; i++) {
        printf("%d ", p_l->vet[i]);
    }
    printf("\n");
}

