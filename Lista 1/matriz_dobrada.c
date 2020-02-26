#include <stdio.h>
#include <stdio.h>

void dobra_matriz(int ***matriz, int linha, int coluna){
    int a, b, i, j;
    int col = coluna, lin = linha, dim_lin = linha, dim_col = coluna;

    while(linha >= 2 || coluna >= 2){
        if(linha == coluna){
            for (a = 0; a < linha; a++){
                for(b = 0; a < (coluna / 2); b++){
                    *matriz[a][b] = *matriz[a][b] + *matriz[a][col];
                    col--;
                }
            }
            dim_lin = dim_lin / 2;
        }
        else if(coluna < linha ){
            for(a = 0; a < (linha / 2); a++){
                for(b = 0; b < coluna; b++){
                    *matriz[a][b] = *matriz[a][b] + *matriz[lin][b];
                    lin--;
                }
            }
            dim_col = dim_col / 2;
        }
        else if(linha == 2 && coluna == 2){
            for(i = 0; i < 2; i++){
                for(j = 0; j < 2; j++){
                    printf("%d ", matriz[i][j]);
                }
            }
        }
    printf("a");
    }
}

int main(){
    int n, i, j;

    printf("Digite o tam: ");
    scanf("%d", &n);
    int matriz[n][n];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++){
        printf("Digite o valor: ");
        scanf("%d", &matriz[i][j]);
        }
    }
    dobra_matriz(matriz, n, n);
}
