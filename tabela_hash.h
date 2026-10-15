#include <stdbool.h>

#ifndef TABELA_HASH_H
#define TABELA_HASH_H

typedef struct node {
	struct node *proximo; //8 bytes (offset 0 a 7 -> inicia no 0 -> múltiplo de 8)
	int dado; //4 bytes (offset 8 a 11 -> inicia no 8 -> múltiplo de 4)
	//(soma dos bytes = 12 -> não é múltiplo do maior sizeof = 8 -> compilador completa com padding no final)
	//4 bytes de padding (soma dos bytes = 16 -> múltiplo de 8)
	//sizeof(node) = 16 bytes
} node;

typedef struct {
	node **vetor; 
	int m; 
} tabela_hash;

node *criar_head(int valor);
node *inserir_head(node *head, int valor);
void libera_memoria_lista_encadeada(node *head); 
bool ehPrimo(int n);
int encontra_primo(int n);
tabela_hash *criar_tabela_hash(int qtd_nos);
void libera_memoria_tabela_hash(tabela_hash *minha_tabela);
int funcao_hash(int valor, int m);
void insercao_na_tabela_hash(node *head, tabela_hash *minha_tabela);
bool busca_na_tabela_hash(int n, tabela_hash *minha_tabela);

#endif