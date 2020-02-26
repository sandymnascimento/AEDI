#include <stdio.h>
#include <math.h>

int potencia(int *v, int n){
    int i;
    int cont;

    cont = 0;
    i = 0;
    for(i; i < n; i++)
    {
        if(v[i] == 0 || v[i] == 1)
            cont++;
        else if(v[i] < 0)
            i++;
        else{
            while(v[i] >= 2 && v[i] % 2 == 0)
            {printf("a");
                v[i] = v[i] / 2.0;

                if(v[i] == 1.0){
                    cont++; printf("b");}
            }
        }
    }
    printf("%d", cont);
    return cont;
}
int main() {
    int n;
    int i;
    int resultado;

    scanf("%d", &n);
    int vetor[n];

    for(i = 0; i < n; i++)
        scanf("%d", &vetor[i]);

    resultado = potencia(vetor, n);
    printf("Quantidade de potencias %d", resultado);
    return 0;
}
