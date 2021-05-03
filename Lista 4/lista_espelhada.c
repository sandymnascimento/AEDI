#include <stdlib.h>
//lista_espelhada, pilha_dinamica, fila_dinamica

typedef struct Node Node;
struct Node {
    int data;
    Node *next;
};

typedef struct Pilha Pilha;
struct Pilha {
   Node *topo;
};

int lista_espelhada(Node *lista) {
    Node *inicio = lista;
    Pilha *pilha = cria_pilha();
    
    while(lista) {
        empilhar(pilha, lista->data);
        lista = lista->next;
    }
    while(inicio){
        if(inicio->data == pilha->topo->data){
            inicio = inicio->next;
            Node *tmp = pilha->topo;
            pilha->topo = pilha->topo->next;
            free(tmp);
        }
        else{
            liberar_pilha(pilha);
            return 0;
            
        }
    }
    liberar_pilha(pilha);
    return 1;
}