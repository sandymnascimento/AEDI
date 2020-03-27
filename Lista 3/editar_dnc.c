#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;
struct Node {
   char data;
   Node *next;
};

void inserir(Node **primeiro, char valor) {
	Node *novo = malloc(sizeof(Node));
	novo->data = valor ;
	novo->next = NULL;

	if (*primeiro == NULL) {
		*primeiro = novo;
	} else {
		Node *atual = *primeiro;
		while (atual->next != NULL) {
			atual = atual->next;
		}
		atual->next = novo;
	}
}

void imprimir(Node *primeiro) {
	Node *atual;
	for (atual = primeiro; atual != NULL; atual = atual->next) {
		printf("%c ", atual->data);
	}
	printf("\n");
}

Node *editar_dna(Node *dna_original, Node *seq_edicao) {
    Node *inicio_seq = seq_edicao;

  while(dna_original != NULL){
    if(dna_original->next->data == seq_edicao->data){
        Node *tmp = dna_orginal;
        dna_original = dna_orginal->next;
        while(seq_edicao != NULL){
            if(dna_original == seq_edicao){
                dna_original = dna_original->next;
                seq_edicao = seq_edicao->next;
            }else{
                dna_original = dna_original->next;
                seq_edicao = inicio_seq;
                break;
            }
        }
        if(seq_edicao == NULL){ //fazer as devidas remocoes
            tmp->next = dna_original; // REMOVER O QUE TIVER ENTRE ELES
            seq_edicao = inicio_seq; LALA
        }
    }
    else{
        dna_original = dna_original->next;
    }
  }


}

int main() {
	Node *p2 = NULL, *p1 = NULL;

	inserir(&p2, 'A');
	inserir(&p2, 'C');
	inserir(&p2, 'G');
	inserir(&p2, 'T');
	inserir(&p2, 'A');
	inserir(&p2, 'G');
	inserir(&p2, 'A');
	inserir(&p2, 'C');
	inserir(&p2, 'G');
	inserir(&p2, 'T');
	inserir(&p2, 'T');
	inserir(&p2, 'C');
	inserir(&p2, 'T');
	inserir(&p2, 'A');
	inserir(&p1, 'C');
	inserir(&p1, 'G');
	inserir(&p1, 'A');
	imprimir(p2);
    editar_dna(p2, p1);
	imprimir(p2);

	return 0;
}
