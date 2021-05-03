#include <stdlib.h>
//#include "abb_menor_chave.h"

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

int menor_chave_comum(NoArvore *raiz1, NoArvore *raiz2) {
    if(raiz1 == NULL || raiz2 == NULL) return -1;
    int menor = menor_chave_comum(raiz1->esq, raiz2);
    if(menor != -1) return menor;
    else if(raiz1->chave == raiz2->chave) {
        menor = raiz1->chave;
        return menor;
    }
    menor = menor_chave_comum(raiz1->dir, raiz2);
    if(menor != -1) return menor;
    menor = menor_chave_comum(raiz1, raiz2->esq);
    if(menor != -1) return menor;
    menor = menor_chave_comum(raiz1, raiz2->dir);
    return menor;
}