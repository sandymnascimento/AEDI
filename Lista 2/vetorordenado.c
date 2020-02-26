#include <stdlib.h>
//#include "vetorordenado.h"

void adiciona_ordenado(double **dest, double *inicial, int n, double novo_num){
    int i;

    for(i = 0; i < n; i++){
            if(novo_num > inicial[i])
                *dest[i] = inicial[i];
            if(novo_num < inicial[i]){
                *dest[i] = novo_num;
                *dest[++i] = inicial[i];
            }
            printf("a");
    }
    for(i = 0; i < n; i++){
        printf("%lf", *dest[i]);
    }
    printf("b");
}
int main(){
    double vetor[] = {4, 7, 8, 90, 100};
    double dest[6];
    double *desti = &dest;
    double *destin = &desti;
    adiciona_ordenado(destin, vetor, 6, 95.2);
    return 0;

}
