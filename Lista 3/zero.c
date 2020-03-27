#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;
struct Node {
   char data;
   Node *next;
};

void inserir(Node **primeiro, char valor) {
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

Node *aguaDNA(Node *atual){
    Node *inicio = atual;
    while(atual->data == 'C' || atual->data == 'G'){
        if(atual->next != NULL){
            inicio = atual->next;
            free(atual);
            Node *atual = inicio;}
        else{
            atual = NULL;
            return atual;}
    }
    return inicio;
}
void imprimir(Node *primeiro) {
	Node *atual;
	for (atual = primeiro; atual != NULL; atual = atual->next) {
		printf("%c ", atual->data);
	}
	printf("\n");
}

int main() {
	Node *p2 = NULL;

	inserir(&p2, 'C');
	inserir(&p2, 'C');
	inserir(&p2, 'G');
	inserir(&p2, 'G');
	inserir(&p2, 'C');
	inserir(&p2, 'G');
	inserir(&p2, 'C');
	inserir(&p2, 'C');
	inserir(&p2, 'C');
	inserir(&p2, 'G');
	inserir(&p2, 'G');
	inserir(&p2, '0');
	imprimir(p2);
    aguaDNA(p2);
	imprimir(p2);

	return 0;
}
