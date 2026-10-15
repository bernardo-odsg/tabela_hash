#include <stdlib.h>
#include <assert.h>
#include "tabela_hash.h"

node *criar_head(int valor) {
     node *head = malloc(sizeof(*head));
     if (head == NULL) {
         return NULL;
     }
     head -> dado = valor;
     head -> proximo = NULL;
     return head;
}

node *inserir_head(node *head, int valor) {
     node *nova_head = criar_head(valor);
     if (nova_head == NULL) {
        return NULL;
     }
     nova_head -> proximo = head;
     return nova_head;
}

bool eh_Primo(int n) {
	assert (n > 1);
	if (n == 2) {
	   return true;
	}
	else {
	   if (n % 2 == 0) {
	      return false;
	   }
	   else {
	       int d = 3;
	       while (d * d <= n) {
	           if (n % d == 0) {
	              return false;
	           }
	           d += 2;
	       }
           return true;
	   }
	}
}

int encontra_primo(int n) {
	if (n % 2 == 0) {
	   n += 1;
	}
	else {
	   n += 2;
	}
	while (! eh_Primo(n)) {
	   n += 2;
	}
	return n;
}


tabela_hash *criar_tabela_hash(int qtd_nos) { 
	tabela_hash *minha_tabela = malloc(sizeof(*minha_tabela));
	if (minha_tabela == NULL) {
		return NULL;
	}
	minha_tabela -> m = encontra_primo(qtd_nos);
	minha_tabela -> vetor = calloc(minha_tabela -> m, sizeof(*(minha_tabela -> vetor)));
	if (minha_tabela -> vetor == NULL) {
		return NULL;
	}
	return minha_tabela;
}

int funcao_hash(int dado, int m) {
    return dado % m;
}

void insercao_na_tabela_hash(node *head, tabela_hash *minha_tabela) {
    while (head != NULL) {
       int posicao = funcao_hash(head -> dado, minha_tabela -> m);
       if ((minha_tabela -> vetor)[posicao] == NULL) {
       	   (minha_tabela -> vetor)[posicao] = criar_head(head -> dado);
       }
       else {
       	   (minha_tabela -> vetor)[posicao] = inserir_head((minha_tabela -> vetor)[posicao], head -> dado);
       	   if ((minha_tabela -> vetor)[posicao] == NULL) {
       	   	   return;
       	   }
       }
       head = head -> proximo;
    }
}

bool busca_na_tabela_hash(int n, tabela_hash *minha_tabela) {
	int posicao = funcao_hash(n, minha_tabela -> m);
	node *endereco_atual_na_posicao = (minha_tabela -> vetor)[posicao];
	while (endereco_atual_na_posicao != NULL) {
		if (endereco_atual_na_posicao -> dado == n) {
			return true;
		}
		endereco_atual_na_posicao = endereco_atual_na_posicao -> proximo;
	}
	return false;
}

void libera_memoria_lista_encadeada(node *head) {
     if (head == NULL) {
     	return;
     }
     node *head_auxiliar;
     while (head -> proximo != NULL) {
     	head_auxiliar = head -> proximo;
     	free(head);
     	head = head_auxiliar;
     }
     free(head);
}

void libera_memoria_tabela_hash(tabela_hash *minha_tabela) {
	for (int i = 0 ; i < minha_tabela -> m ; i++) {
		libera_memoria_lista_encadeada((minha_tabela -> vetor)[i]);
	}
	free(minha_tabela -> vetor);
	free(minha_tabela);
}