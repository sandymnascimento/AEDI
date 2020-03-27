#include <stdlib.h>
//#include "inverte.h"

char *inverte_texto(char *texto){
    int i = 0, a, cont = 0;

    while(texto[i] != '\0')
    {
        cont++;
        i++;
    }

    char *inverte = malloc(sizeof(char) * (cont + 1));
    a = cont - 1;

    for(i = 0; i < cont; i ++)
    {
        inverte[i] = texto[a];
        a--;

    }
        inverte[cont] = '\0';
    return inverte;
}
int main(){
    char texto[] = "sandy, limao";
    puts(inverte_texto(texto));
    return 0;
}
