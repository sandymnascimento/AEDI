#include <stdlib.h>
//#include "inverte.h"

char *inverte_texto(char *texto){
    int i, a, cont = 0;
    while(texto){
        cont++;
    }
    char inverte[cont + 1];
     a  = cont;
    for(i = 0; i < cont; i ++){
        texto[a] = inverte[i];
        a--;
    }
        puts(inverte);
}
int main(){
    char texto[] = "ABCDEF";
    inverte_texto(texto);
    return 0;
}
