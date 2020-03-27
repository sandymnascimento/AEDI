#include <stdlib.h>

typedef struct Node Node;
struct Node {
   int data;
   Node *next;
};

int compararListasLigadas(Node *lista1, Node *lista2) {
  if(lista1 == NULL && lista2 == NULL)
    return 1;
  if((lista1 == NULL && lista2 != NULL) || (lista1 != NULL && lista2 == NULL))
    return 0;

  while(lista1 != NULL && lista2 != NULL){
    if(lista1->data == lista2->data){
        if(lista1->next != NULL && lista2->next != NULL){
            lista1 = lista1->next;
            lista2 = lista2->next;
        }
        else if (lista1->next == NULL && lista2->next == NULL)
            return 1;
        else
            return 0;
    }
    else
        return 0;
  }
}
