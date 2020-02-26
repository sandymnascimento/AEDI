#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comprimento_maior_palavra(char texto[]) {
    int i;
    int maior = 0, cont = 0;

    for(i = 0; i < 100; i++){
       if(texto[i] != ' ' && texto[i] != '\0')
            cont++;
       else if(texto[i] == ' '){
            if(cont >= maior)
                maior = cont;
            cont = 0;
       }
       else if(texto[i] == '\0'){
            if(--cont >= maior)
                maior = cont;
            break;
       }
    }
    return maior;
}

int main() {

	char texto[101];
	fgets(texto, 101, stdin);

	int cmp = comprimento_maior_palavra(texto);
	printf("%d\n", cmp);

	return 0;
}
