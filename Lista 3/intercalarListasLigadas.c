#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
   int data;
   Node *next;
};
void inserir(Node **primeiro, int valor) {
	Node *novo = malloc(sizeof(Node));
	novo->data = valor ;
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
void imprimir(Node *primeiro) {
	Node *atual;
	for (atual = primeiro; atual != NULL; atual = atual->next) {
		printf("%d ", atual->data);
	}
	printf("\n");
}
Node* intercalarListasLigadas(Node *lista1, Node *lista2){
    Node *novo = NULL, *inicio = novo;
    if(lista1 == NULL && lista2 == NULL) return novo;
    if(lista1 != NULL && lista2 == NULL) return lista1;
    if(lista1 == NULL && lista2 != NULL) return lista2;

   while(lista1 != NULL || lista2 != NULL){
        if(lista1->data == lista2->data){
            novo = lista1; printf("%d ", novo->data);
            novo = novo->next;
            novo = lista2; printf("%d ", novo->data);
            lista1 = lista1->next;
            lista2 = lista2->next;
            novo = novo->next;
        }
        else if(lista1->data < lista2->data || lista2 == NULL){
            novo = lista1; printf("%d ", novo->data);
            novo = novo->next;
            lista1 = lista1->next;
        }
        else if(lista2->data < lista1->data || lista1 == NULL){
            novo = lista2; printf("%d ", novo->data);
            novo = novo->next;
            lista2 = lista2->next;
        }
    }
    return (inicio);
}
int main() {
	Node *p2 = NULL, *p1 = NULL, *p3 = NULL;

	inserir(&p2, 1);
	inserir(&p2, 2);
	inserir(&p2, 4);
	inserir(&p2, 5);
	inserir(&p2, 9);
	inserir(&p1, 1);
	inserir(&p1, 5);
	inserir(&p1, 6);
	inserir(&p1, 7);
	inserir(&p1, 8);
	imprimir(p1);
	imprimir(p2);
    p3 = intercalarListasLigadas(p1, p2);
    imprimir(p3);

	return 0;
}
