#include <stdlib.h>
#include <ctype.h>
//#include "disciplinas_ordenadas.h"

typedef struct Disciplina Disciplina;
struct Disciplina {
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};

typedef struct Curso Curso;
struct Curso {
    int cod_curso;
    char *nome_curso;
    Disciplina *ultima_disciplina;
};

void insere_disciplina(Curso *curso, Disciplina *nova_disciplina) { / recebe um curso e uma disciplina nova

    if(curso)
    curso->ultima_disciplina->requisitos
}

