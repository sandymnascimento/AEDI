#include <stdlib.h>
#include "pilha_estatica.h"

Pilha *cria_pilha(int tamanho_vetor) {
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->vetor = malloc(sizeof(int)*tamanho_vetor);
    pilha->topo = -1;
    pilha->tamanho_vetor = tamanho_vetor;
    return pilha;
}

int empilhar(Pilha *pilha, int valor) {
    if(pilha->topo == pilha->tamanho_vetor - 1) return 0;

    pilha->topo++;
    pilha->vetor[pilha->topo] = valor;
    return 1;
}

int desempilhar(Pilha *pilha, int *valor) {
    if(pilha->topo == -1) return 0;
    *valor = pilha->vetor[pilha->topo];
    pilha->topo--;
	return 1;
}

void liberar_pilha(Pilha *pilha) {
    free(pilha->vetor);
	free(pilha);
}