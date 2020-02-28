#include <stdlib.h>
#include "disciplina.h"

typedef struct Disciplina Disciplina;
struct Disciplina {
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
}
Disciplina* cria_disciplina(int cod, char *nome, int creditos) {
    // Codigo da funcao aqui
}

Disciplina* cria_disciplina_com_requisito(int cod, char *nome, int creditos, int req_cod, char *req_nome, int req_creditos) {
    // Codigo da funcao aqui
}
