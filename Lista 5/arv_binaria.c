#include <stdlib.h>
//#include "arv_binaria.h"

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

int estritamente_binaria(NoArvore *raiz) {
    if(raiz->dir == raiz->esq)
        return 1;
    if((raiz->dir != NULL && raiz->esq != NULL) || (raiz->dir == raiz->esq)) { 
        int raizdir = estritamente_binaria(raiz->dir);
        int raizesq = estritamente_binaria(raiz->esq);
        if(raizdir == 0 || raizesq == 0)
            return 0;
        else
            return 1;
    }
    else
        return 0;
}