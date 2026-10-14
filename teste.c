#include <stdio.h>
#include "tabela_hash.h"
int main() {
	int n, qtd = 0;
	char c_leitura, c_resposta;
	node *head = NULL;
	printf("Digite os valores dos nós a serem criados: ");
	while (scanf("%d", &n) == 1) {
		c_leitura = getchar();
		if (c_leitura == '\n' || c_leitura == ' ' || c_leitura == '\t') {
			qtd += 1;
			if (qtd == 1) {
				if (criar_head(n) != NULL) {
					head = criar_head(n);
				}			
			}
			else {
				if (inserir_head(head, n) != NULL) {
					head = inserir_head(head, n);
				}
			}
			if (c_leitura == '\n') {
				break;
			}
			else {
				while (c_leitura == ' ' || c_leitura == '\t') {
					c_leitura = getchar();
				}
				if (c_leitura == '\n') {
					break;
				}
				ungetc(c_leitura, stdin);
			} 
		}
		else {
			break;
		}
	}
	if (qtd == 0 || head == NULL) {
		return 1;
	}
	while (c_leitura != '\n') {
		c_leitura = getchar(); 
	}
	tabela_hash *minha_tabela = criar_tabela_hash(qtd);
	if (minha_tabela == NULL) {
		return 1;
	}
	insercao_na_tabela_hash(head, minha_tabela);
	do {
		printf("Deseja fazer uma busca? (S) ou (N): ");
		do {
			c_resposta = getchar();
		} while (c_resposta != 'S' && c_resposta != 'N');
		if (c_resposta == 'S') {
			printf("Digite o valor que deseja buscar na lista encadeada: ");
			while (scanf("%d", &n) == 0) {
				c_leitura = getchar();
			}
			if (busca_na_tabela_hash(n, minha_tabela)) {
				printf("%d se encontra na lista\n", n);
			}
			else {
				printf("%d nao se encontra na lista\n", n);
			}
		}
	} while (c_resposta == 'S');
	libera_memoria_tabela_hash(minha_tabela);
	libera_memoria_lista_encadeada(head);
	return 0;
}