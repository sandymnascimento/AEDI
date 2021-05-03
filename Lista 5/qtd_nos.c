#include <stdlib.h>
//#include "qtd_nos.h"

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

int numero_nos(NoArvore *raiz){
    if(raiz == NULL)
        return 0;
    int raizdir = numero_nos(raiz->dir);
    int raizesq = numero_nos(raiz->esq);
    return raizdir + raizesq + 1;
}

int numero_nos_folha(NoArvore *raiz){
    if(raiz == NULL)
        return 0;
        
    int raizesq = numero_nos_folha(raiz->esq);
    int raizdir = numero_nos_folha(raiz->dir);
    if(raiz->esq == NULL && raiz->dir == NULL)
        return raizdir + raizesq + 1;
    else
        return raizdir + raizesq;
}

int numero_nos_internos(NoArvore *raiz){
    if(raiz == NULL)
        return 0;
    int raizesq = numero_nos_internos(raiz->esq);
    int raizdir = numero_nos_internos(raiz->dir);
    if(raiz->esq != NULL || raiz->dir != NULL)
        return raizdir + raizesq + 1;
    else
        return raizdir + raizesq;
}