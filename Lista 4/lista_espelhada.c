#include <stdlib.h>
#include "lista_espelhada.h"
#include "pilha_dinamica.h"
#include "fila_dinamica.h"

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