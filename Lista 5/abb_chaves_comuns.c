#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

int qtd_chaves_comuns(NoArvore *raiz1, NoArvore *raiz2) {
    if(raiz1 == NULL || raiz2 == NULL) return 0;
    
    int esq = qtd_chaves_comuns(raiz1->esq, raiz2);
    int dir = qtd_chaves_comuns(raiz1->dir, raiz2);
    esq = qtd_chaves_comuns(raiz2->esq, raiz1);
    dir = qtd_chaves_comuns(raiz2->dir, raiz1);
    
    if(raiz1->chave == raiz2->chave) return esq + dir + 1;
    else return esq + dir;
}
