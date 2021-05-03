#include <stdlib.h>

typedef struct Node Node;
struct Node {
   int data;
   Node *next;
};

Node *selectionsort(Node *inicio, int *trocas, int *comparacoes) {
    *trocas = 0,  *comparacoes = 0;
    if(inicio == NULL) return NULL;
    
    Node *atual = inicio, *compara = NULL, *tmp = NULL;
    int i, j, menor;
    
    while(atual->next){
        menor = atual->data;
        compara = atual->next;
        while(compara){
            if(compara->data < menor){
                tmp = compara;
                menor = compara->data;
            }
            *comparacoes = *comparacoes + 1;
            compara = compara->next;
        }
        if(menor != atual->data){
            tmp->data = atual->data;
            atual->data = menor;
            *trocas = *trocas + 1;
        }
        atual = atual->next;
    }
    return inicio;
}