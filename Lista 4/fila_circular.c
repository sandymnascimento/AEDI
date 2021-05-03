#include <stdlib.h>

typedef struct Fila Fila;
struct Fila {
   int *vetor;
   int inicio, fim;
   int tamanho_vetor;
};

Fila *cria_fila(int tamanho_vetor) {
    Fila *fila = malloc(sizeof(Fila));
    fila->vetor = malloc(sizeof(int)*tamanho_vetor);
    fila->tamanho_vetor = tamanho_vetor;
    fila->inicio = 0;
    fila->fim = 0;
    return fila;
}

int enfileirar(Fila *fila, int valor) {
    int final = (fila->fim + 1) % fila->tamanho_vetor;
    if(final == fila->inicio) return 0;
    fila->vetor[fila->fim] = valor;
    fila->fim = final;
    return 1;
}

int desenfileirar(Fila *fila, int *valor) {
    if(fila->inicio == fila->fim) return 0;
    *valor = fila->vetor[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->tamanho_vetor;
    return 1;
}

void liberar_fila(Fila *fila) {
    free(fila->vetor);
    free(fila);
}