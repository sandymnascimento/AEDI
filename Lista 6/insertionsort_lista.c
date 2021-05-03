#include <stdlib.h>

typedef struct DNode DNode;
struct DNode {
   int data;
   DNode *prev, *next;
};

DNode *insertionsort(DNode *inicio, int *comparacoes){
    DNode *comeco = inicio, *lista = comeco;
    int atual;
    *comparacoes = 0;
    
    while(comeco){
        atual = comeco->data;
        if(comeco->prev != NULL) lista = comeco->prev;
        while((lista != NULL || *comparacoes == 0) && atual < lista->data){
            lista->next->data = lista->data;
            lista->data = atual;
            *comparacoes = *comparacoes + 1;
            if(lista->prev == NULL) break;
            lista = lista->prev;  
        }
        if(atual > lista->data) *comparacoes = *comparacoes + 1;
        
        comeco = comeco->next;
    }
    return inicio;
}