#include <stdlib.h>
#include "pilha_dinamica.h"

Pilha *cria_pilha() {
	Pilha *novo = malloc(sizeof(Pilha));
	novo->topo = NULL;
	return novo;
}

int empilhar(Pilha *pilha, int valor) {
	Node *novo = malloc(sizeof(Node));
	
	if (novo == NULL) return 0;
	
	novo->data = valor;
	novo->next = pilha->topo;
	pilha->topo = novo;
	
	return 1;
}

int desempilhar(Pilha *pilha, int *valor) {
	if (pilha->topo == NULL) return 0;
	
	Node *remover = pilha->topo;
	pilha->topo = pilha->topo->next;
	*valor = remover->data;
	free(remover);
	return 1;
}

void liberar_pilha(Pilha *pilha) {
    Node* rem = pilha->topo;
    
    while (rem !=NULL) {
        Node* tmp = rem->next;
        free(rem);
        rem = tmp;
    }
    
    free(pilha);
}