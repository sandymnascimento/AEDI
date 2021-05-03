#include <stdlib.h>
#include <string.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    char *chave;
    NoArvore *esq, *dir;
};

NoArvore *buscar(NoArvore *raiz, char *chave) {
    if(raiz == NULL) return NULL;
    if(raiz->chave == chave) return raiz;
    if(strcmp(raiz->chave, chave) > 0)
        return buscar(raiz->esq, chave);
    else if(strcmp(raiz->chave, chave) < 0)
        return buscar(raiz->dir, chave);
    else
        return raiz;
}

NoArvore *inserir(NoArvore *raiz, char *chave_nova) {
    if(raiz == NULL){
        char *p = malloc(sizeof(char)*100);
        strcpy(p, chave_nova);
        
        NoArvore *novo = malloc(sizeof(NoArvore));
        novo->chave = p;
        novo->esq = NULL;
        novo->dir = NULL; 
        return novo;
    }
    if(strcmp(raiz->chave, chave_nova) < 0)
        raiz->dir = inserir(raiz->dir, chave_nova);
    else if(strcmp(raiz->chave, chave_nova) > 0)
        raiz->esq = inserir(raiz->esq, chave_nova);
    
    return raiz;
}

NoArvore *remover(NoArvore *raiz, char *chave) {
    if(raiz == NULL) return NULL;
    
    if(strcmp(raiz->chave, chave) < 0)
        raiz->dir = remover(raiz->dir, chave);
    
    else if(strcmp(raiz->chave, chave) > 0)
        raiz->esq = remover(raiz->esq, chave);
    
    else{
        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz->chave);
            free(raiz);
            return NULL;
        }
        else if(raiz->esq == NULL){
            NoArvore *raizdir = raiz->dir;
            free(raiz->chave);
            free(raiz);
            return raizdir;
        }    
        else if(raiz->dir == NULL){
            NoArvore *raizesq = raiz->esq;
            free(raiz->chave);
            free(raiz);
            return raizesq;
        }
        else {
            NoArvore *busca = raiz->dir;
            while(busca != NULL) {
                if(busca->esq == NULL) 
                    strcpy(raiz->chave, busca->chave);
                busca = busca->esq;
            }
            char *menor = malloc(sizeof(char)*100);
            strcpy(menor, raiz->chave);
            raiz->dir = remover(raiz->dir, menor);
            free(menor);
        }
    }
    return raiz;
}

void liberar_arvore(NoArvore *raiz) {
    if(raiz == NULL) return;
    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz->chave);
    free(raiz);
}
