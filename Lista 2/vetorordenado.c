#include <stdlib.h>
#include <stdio.h>
//#include "vetorordenado.h"

void adiciona_ordenado(double **dest, double *inicial, int n, double novo_num){
    int i;

    for(i = 0; i < n; i++){
           printf("b");
            if(novo_num > inicial[i])
                *dest[i] = inicial[i];
            else if(novo_num <= inicial[i]){
                *dest[i] = novo_num;
                *dest[i + 1] = inicial[i];
            }
            printf("%.lf %.lf ", *dest[i], inicial[i]);
    }
    for(i = 0; i < n; i++){
        printf("%lf", *dest[i]);
    }
    printf("c");
}
int main(){
    double vetor[] = {4.2, 7.3, 8.89, 90.3, 100};
    double dest[6];
    double *desti = dest;
    double **destin = &desti;
    adiciona_ordenado(destin, vetor, 6, 95.2);

    return 0;

}
