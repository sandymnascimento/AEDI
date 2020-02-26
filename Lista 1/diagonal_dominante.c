#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, j, valor, soma;

    scanf("%d", &n);
    int matriz[n][n];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        soma = 0; valor = 0;
        for(j = 0; j < n; j++){
            if(i == j)
                valor = abs(matriz[i][j]);
            else
              soma = soma + abs(matriz[i][j]);
        }
        if(valor < soma){
            printf("NAO.");
            break;
        }
    }
    if(valor > soma)
        printf("SIM.");
    return 0;
}
