#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pilha Pilha;
struct Pilha {
   int *vetor;
   int topo;
   int tamanho_vetor;
};

int verificar(char *vetor, Pilha *pilha);
void desempilhar(Pilha *pilha);
void empilhar(Pilha *pilha, char valor);
Pilha *cria_pilha(int tamanho_vetor);

int main() {
    char *vetor = malloc(sizeof(char)*100);
    scanf("%[^\n]", vetor);

    int tam = 0;
    while(vetor[tam] != '\0')
        tam++;

    Pilha *pilha = cria_pilha(tam - 1);

    int i = verificar(vetor, pilha);
    if(i == 1)
        printf("SIM\n");
    else
        printf("NAO\n");
    free(pilha);
    free(pilha->vetor);
    free(vetor);
    return 0;
}

Pilha *cria_pilha(int tamanho_vetor) {
   Pilha *pilha = malloc(sizeof(Pilha));
   pilha->vetor = malloc(sizeof(char)*tamanho_vetor);
   pilha->topo = -1;
   pilha->tamanho_vetor = tamanho_vetor;

   return pilha;
}

void empilhar(Pilha *pilha, char valor) {
   if(pilha->topo == pilha->tamanho_vetor - 1)
        return;
   pilha->topo = pilha->topo + 1;      
   pilha->vetor[pilha->topo] = valor;
}

void desempilhar(Pilha *pilha) {
   if(pilha->topo == -1)
      return;
   pilha->vetor[pilha->topo] == '\0';
   pilha->topo--;
}

int verificar(char *vetor, Pilha *pilha) {
    int i;
    for (i = 0; vetor[i] != '\0'; i++) {
        if(vetor[i] == '(')
            empilhar(pilha, '(');
        else if(vetor[i] == '{')
            empilhar(pilha, '{');
        else if(vetor[i] == '[')
            empilhar(pilha, '[');
        else if(vetor[i] == ')') {
            if(pilha->vetor[pilha->topo] == '(')
                desempilhar(pilha);
            else 
                return 0;
        }
        else if(vetor[i] == '}') {
            if(pilha->vetor[pilha->topo] == '{')
                desempilhar(pilha);
            else 
                return 0;
        }
        else if(vetor[i] == ']') {
            if(pilha->vetor[pilha->topo] == '[')
                desempilhar(pilha);
            else 
                return 0;
        }
    }
    if(pilha->topo > -1)
        return 0;
    else
        return 1;
}