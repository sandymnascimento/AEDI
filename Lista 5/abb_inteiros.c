#include <stdlib.h>
//"abb_inteiros

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

NoArvore *buscar(NoArvore *raiz, int chave) {
    if(raiz == NULL) return NULL;
    
    if(raiz->chave == chave) return raiz;
    
    if(raiz->chave > chave)
        return buscar(raiz->esq, chave);
        
    if(raiz->chave < chave)
        return buscar(raiz->dir, chave);
}

NoArvore *inserir(NoArvore *raiz, int chave_nova) {
    if(raiz == NULL){
        NoArvore *novo = malloc(sizeof(NoArvore));
        novo->chave = chave_nova;
        novo->esq = NULL;
        novo->dir = NULL; 
        raiz = novo;
        return raiz;
    }
    if(raiz->chave < chave_nova)
        raiz->dir = inserir(raiz->dir, chave_nova);
    
    if(raiz->chave > chave_nova)
        raiz->esq = inserir(raiz->esq, chave_nova);
    
    return raiz;
}

NoArvore *remover(NoArvore *raiz, int chave) {
    if(raiz == NULL) return NULL;
    
    if(raiz->chave < chave)
        raiz->dir = remover(raiz->dir, chave);
    
    else if(raiz->chave > chave)
        raiz->esq = remover(raiz->esq, chave);
    
    else{
        if(raiz->esq == NULL && raiz ->dir == NULL){
            free(raiz);
            return NULL;
        }
        else if(raiz->esq == NULL){
            NoArvore *raizdir = raiz->dir;
            free(raiz);
            return raizdir;
        }    
        else if(raiz->dir == NULL){
            NoArvore *raizesq = raiz->esq;
            free(raiz);
            return raizesq;
        }
        else {
            NoArvore *busca = raiz->dir;
            int menor;
            while(busca != NULL) {
                if(busca->esq == NULL) 
                    menor = busca->chave;
                busca = busca->esq;
            }
            raiz->chave = menor;
            raiz->dir = remover(raiz->dir, menor);
        }
    }
    return raiz;
}