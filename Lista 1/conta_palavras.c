#include <stdio.h>

int main()
{
    int i;
    int cont = 0;
    char frase[100];

    gets(frase);
    for(i = 0; i < 100; i++){
        if(frase[i] == ' ')
            cont++;
        else if(frase[i] == '\0')
        {
            cont++;
            break;
        }
    }
    printf("%d", cont);
}
