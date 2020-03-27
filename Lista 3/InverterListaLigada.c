#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    Node *next;
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
Node* inverterListaLigada(Node *lista) {
  if(lista == NULL)
    return lista;

    Node *tmp, *inicio = lista, *fim = NULL;

    while(inicio != NULL){
       tmp = inicio->next;
       inicio->next = fim;
       fim = inicio;
       inicio = tmp;
    }
        lista = fim;
        return lista;
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

	/*inserir(&p2, 11);
	inserir(&p2, 22);
	inserir(&p2, 33);
	imprimir(p2);*/
    inverterListaLigada(p2);
	imprimir(p2);

	return 0;
}

