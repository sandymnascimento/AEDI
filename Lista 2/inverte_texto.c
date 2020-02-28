#include <stdlib.h>
//#include "inverte.h"

char *inverte_texto(char *texto) {
    int i, j, cont = 0;

    while(texto){
        cont++;
    }
    char inverte[cont];
    for(i = 0; i < cont; i++){
        for(j = cont; j >= 0; j++){
            inverte[j] = texto[i];
        }
    }
    return inverte;
}
int main(){
    char texto[] = "abcdef";
    inverte_texto(texto);
    for()
}
