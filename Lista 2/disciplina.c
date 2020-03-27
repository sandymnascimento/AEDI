#include <stdlib.h>
#include <stdio.h>

typedef struct Disciplina Disciplina;
struct Disciplina {
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};
Disciplina* cria_disciplina(int cod, char *nome, int creditos) {
    Disciplina *disciplina;
    disciplina = malloc(sizeof(Disciplina));


    disciplina->nome = nome;
    disciplina->cod = cod;
    disciplina->creditos = creditos;

    return disciplina;
}

Disciplina* cria_disciplina_com_requisito(int cod, char *nome, int creditos, int req_cod, char *req_nome, int req_creditos) {
    Disciplina *d_requisito;
    d_requisito = malloc(sizeof(Disciplina));

    d_requisito->nome = nome;
    d_requisito->cod = cod;
    d_requisito->creditos = creditos;

    d_requisito->requisito = malloc(sizeof(Disciplina));
    d_requisito->requisito->nome = req_nome;
    d_requisito->requisito->cod = req_cod;
    d_requisito->requisito->creditos = req_creditos;

    return d_requisito;
}
int main(){
    char nome[] = "Algoritmos e estrutura de dados";
    int cod = 1823;
    int creditos = 4;
    char rnome[] = "Programação Estruturada";
    int rcod = 1729;
    int rcreditos = 4;

    cria_disciplina_com_requisito(cod, nome, creditos, rcod, rnome, rcreditos);

    return 0;
}
