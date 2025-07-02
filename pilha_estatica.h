/****************************************************************
Prototipos e definicoes das operacoes sobre Pilhas
*****************************************************************/


/*Define o tamanho da pilha e estrutura*/
#define MAXPILHA 50


typedef struct stack{
	 char topo;
	 int item[MAXPILHA];
} Pilha;

/*Inicializa a pilha*/
void cria_pilha(Pilha *ps);
/*Verifica se a pilha esta vazia*/
int pilha_vazia(Pilha *ps);
/*Verifica se a pilha esta cheia*/
int pilha_cheia(Pilha *ps);
/*Adiciona um item na pilha*/
void insere_pilha(Pilha *ps, char x);
/*Remove um item da pilha e retorna-o*/
char remove_pilha(Pilha *ps);
/*Retorna o ultimo item da pilha*/
char elem_topo(Pilha *ps);
/*Remove todos os elementos da pilha */
void libera_pilha(Pilha *ps);
