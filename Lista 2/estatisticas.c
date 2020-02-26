#include <stdlib.h>
//#include "estatisticas.h"

void estatisticas(double *lista_numero, int qtd, double *menor, double *maior, double *media, double *soma){
        int i, j;

        for(i = 0; i < qtd; i++){
                for(j = 0; j < qtd; j++){
                        if(lista_numero[i] < lista_numero[j] && lista_numero[i] < *menor)
                                *menor = lista_numero[i];
                        if(lista_numero[i] > lista_numero[j] && lista_numero[i] > *maior)
                                *maior = lista_numero[i];
                }
        }
        for(i = 0; i < qtd; i++){
                *media = *media + abs(lista_numero[i]);
                if(i == qtd - 1)
                    *media = *media / qtd;
                *soma = *soma + lista_numero[i];
        }
}
