#include <stdlib.h>
//#include "estatisticas.h"

void estatisticas(double *lista_numero, int qtd, double *menor, double *maior, double *media, double *soma){
        int i, k;
        *menor = lista_numero[0];
        *maior = lista_numero[0];
        *media = 0;
        *soma = 0;

        for(i = 0; i < qtd; i++){
                if(lista_numero[i] < *menor)
                    *menor = lista_numero[i];
                if(lista_numero[i] > *maior)
                    *maior = lista_numero[i];

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
