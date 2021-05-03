#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int *vetor, int tam);
void ordena_vetor(int *vetor, int tam);

int main(int argc, char** argv) {
    int i, j;
    
    scanf("%d", &i);
    
    int vetor[i];
    
    for(j = 0; j < i; j++)
        scanf("%d", &(vetor[j]));
    
    imprime_vetor(vetor, i);
    ordena_vetor(vetor, i);
    
    return (EXIT_SUCCESS);
}

void ordena_vetor(int vetor[], int tam){
    int i, j, menor, tmp = 0, cont = 0;
    
    for(i = 0; i < tam - 1; i++){
        menor = i;
        for(j = i + 1; j < tam; j++){
            if(vetor[j] < vetor[menor])
                menor = j;
        }
        if(menor != i){
            tmp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = tmp;
            cont++;
        }
        imprime_vetor(vetor, tam);
    }
    imprime_vetor(vetor, tam);
    printf("%d\n", cont);
}

void imprime_vetor(int vetor[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        if(i == tam - 1) printf("%d", vetor[i]);
        else printf("%d ", vetor[i]);
    }
    printf("\n");
}