#include <stdlib.h>
#include "requisitos.h"

typedef struct Disciplina Disciplina;
struct Disciplina {
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd) {
    qtd = 0;

    if(disciplina->requisito == NULL)
        return 0;

    while(disciplina->requisito != NULL){
        qtd++;

        if(disciplina->requisito->requisito != NULL)
            disciplina->requisito = disciplina->requisito->requisito;
        else
            return disciplina->requisito;

}
