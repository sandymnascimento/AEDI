#include <stdlib.h>
//#include "estatisticas.h"

void estatisticas(double *lista_numero, int qtd, double *menor, double *maior, double *media, double *soma){
        int i, k;

        for(i = 0; i < qtd; i++){
                for(k = 0; k < qtd; k++){
                        if(lista_numero[i] < lista_numero[k] && lista_numero[i] < *menor)
                                *menor = lista_numero[i];
                        if(lista_numero[i] > lista_numero[k] && lista_numero[i] > *maior)
                                *maior = lista_numero[i];
                }
        }
        for(i = 0; i < qtd; i++){
                *media = *media + abs(lista_numero[i]);
                if(i == (qtd - 1))
                    *media = *media / qtd;
                *soma = *soma + lista_numero[i];
        }
}
int main(){
        double menor, maior, media, soma;
        double vetor[] = {-13.0, 0.0, -6.0, -26.0, -246.0};
        estatisticas(vetor, 5, &menor, &maior, &media, &soma);
        printf("%.1lf, %.1lf, %.1lf, %.4lf", menor, maior, soma, media);
}
