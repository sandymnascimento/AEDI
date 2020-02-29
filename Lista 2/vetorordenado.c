#include <stdlib.h>

void adiciona_ordenado(double **dest, double *inicial, int n, double novo_num){
    int i, maior = 0;
    double *vetor = malloc(sizeof(double) * (n + 1));
    *dest = vetor;

    for(i = 0; i <= n; i++){
        if(novo_num <= inicial[i]){
            vetor[i] = novo_num;
            novo_num = inicial[i];
        }else if(novo_num > inicial[i])
            vetor[i] = inicial[i];
        if(i == n)
            vetor[i] = novo_num;
    }
}
int main(){
    double vetor[] = {4.2, 7.3, 8.89, 90.3, 180.54};
    double *desti = NULL;
    double **destin = &desti;

    adiciona_ordenado(destin, vetor, 5, 100.0);

    return 0;

}
