#include <stdio.h>
#include <stdlib.h>

void ordenacao(int *v, int num, int cont)
{
    int i;

    if(cont == 0){
        v[0] = num;
    }
    for(i = cont; i >= 0; i--)
    {
        while(num < v[i]){
            v[i+1] = v[i];
            v[i] = num;
        }
    }
}
void print_v(int *v, int N){
    int i;

    for(i = 0; i < N; i++)
        printf("%d ", v[i]);
    printf("\n");
}
int main(){
    int vetor[100];
    int num;
    int cont = 0;

    while(num != -1){
        printf("Digite: ");
        scanf("%d", &num);
        if(num == -1)
            break;
        ordenacao(vetor, num, cont);
        cont++;
        print_v(vetor, cont);
    }
    return 0;
}
