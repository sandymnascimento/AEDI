#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;
struct Node {
   int data;
   struct Node *next;
};

void inserir(Node **primeiro, int valor) {
	Node *novo = malloc(sizeof(Node));
	novo->data = valor;
	novo->next = NULL;

	if (*primeiro == NULL) {
		*primeiro = novo;
	} else {
		Node *atual = *primeiro;
		while (atual->next != NULL) {
			atual = atual->next;
		}
		atual->next = novo;
	}
}

Node* inserirElementoEmUmaPosicao(int posicao, int valor, Node *lista) {
  int cont;
  Node *novo_valor, *inicio = lista;
  novo_valor = malloc(sizeof(Node));
  novo_valor->data = valor;
  novo_valor->next = NULL;

    if(lista == NULL)
        return novo_valor;

    for(cont = 0; cont <= posicao; cont++){
        if(cont + 1 == posicao){
            Node *tmp = lista->next;
            lista->next = novo_valor;
            novo_valor->next = tmp;
            return inicio;
        }else
            lista = lista->next;
    }
}

void imprimir(Node *primeiro) {
	Node *atual;
	for (atual = primeiro; atual != NULL; atual = atual->next) {
		printf("%d ", atual->data);
	}
	printf("\n");
}

int main() {
	Node *p2 = NULL;

	inserir(&p2, 11);
	inserir(&p2, 22);
	inserir(&p2, 33);
	imprimir(p2);
    inserirElementoEmUmaPosicao(2, 44, p2);
	imprimir(p2);

	return 0;
}
