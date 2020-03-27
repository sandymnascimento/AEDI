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
    if(atual->data == 'C' || atual->data == 'G') {
       Node *rem = atual;
       atual->next = rem->next;
       free(rem);
    }
    if(atual->data == '0')
        return atual;

    Node *inicio = atual;
    Node *prox = inicio->next;

    while(prox->data != NULL) {
        if(prox->data == 'C' || prox->data == 'G') {
            Node *tmp = prox;
            atual->next = prox->next;
            prox = prox->next;
            free(tmp);
        }
        else {
            atual = prox;
            prox = prox->next;
        }
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
	imprimir(p2);
    aguaDNA(p2);
	imprimir(p2);

	return 0;
}
