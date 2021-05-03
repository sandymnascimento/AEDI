#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

int sucessor(NoArvore *raiz, int chave) {
    if(raiz == NULL)
        return -1;
        
    int i = sucessor(raiz->esq, chave);
    
    if(raiz->chave > chave || i > chave) {
        if(i > chave) return i;
        
        i = raiz->chave;
        return i;
    }
    else if(i > chave) return i;
    
    i = sucessor(raiz->dir, chave);
    return i;
}

int antecessor(NoArvore *raiz, int chave) {
    if(raiz == NULL) return -1;
    
    int i = antecessor(raiz->dir, chave);
    
    if(raiz->chave < chave && i == -1) {
        i = raiz->chave;
        return i;
    }
    else if(i < chave && i != -1) return i;
    
    i = antecessor(raiz->esq, chave);
    return i;
}