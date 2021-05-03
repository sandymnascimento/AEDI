#include <stdlib.h>

typedef struct Node Node;
struct Node {
   int data;
   struct Node *next;
};

typedef struct Fila Fila;
struct Fila {
   Node *primeiro, *ultimo;
};

Fila *cria_fila() {
    Fila *fila = malloc(sizeof(Fila));
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

int enfileirar(Fila *fila, int valor) {
    Node *novo = malloc(sizeof(Node));
    novo->data = valor;
    novo->next = NULL;
    
    if(fila->primeiro == NULL) {
        fila->primeiro = novo;
        fila->ultimo = fila->primeiro;
    }
    else{
        fila->ultimo->next = novo;
        fila->ultimo = fila->ultimo->next;
    }
    return 1;
}

int desenfileirar(Fila *fila, int *valor) {
    if(fila->primeiro == NULL) return 0;
    
    Node *tmp = fila->primeiro;
    *valor = fila->primeiro->data;
    fila->primeiro = fila->primeiro->next;    
    free(tmp);
    return 1;
}

void liberar_fila(Fila *fila) {
    if(fila->primeiro == NULL) {
        free(fila);
        return;
    }
    Node *tmp = fila->primeiro;
    fila->primeiro = fila->primeiro->next;
    free(tmp);
    liberar_fila(fila);
}