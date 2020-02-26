#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica_matriz(int n, int matriz[n][n]) {
   int i, j;
   int cont_null, cont_true;

    for(i = 0; i < n; i++){
        cont_null = 0;
        cont_true = 0;
        for(j = 0; j < n; j++){
            if(matriz[i][j] == 0)
                cont_null++;
            else if(matriz[i][j] == 1)
                cont_true++;
        }
        if(cont_null != n-1 || cont_true != 1)
            return 0;
   }
   return 1;
}
int main() {

	int n;
	scanf("%d", &n);

	int matriz[n][n];
	int linha, coluna;
	for (linha = 0; linha < n; linha++)
		for (coluna = 0; coluna < n; coluna++)
			scanf("%d", &matriz[linha][coluna]);

	if (verifica_matriz(n, matriz))
		printf("SIM\n");
	else
		printf("NAO\n");

	return 0;
}

