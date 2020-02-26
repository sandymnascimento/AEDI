#include <stdio.h>

int eh_triangular(int n) {
    int i = 1;

    for(i; i <= 1000; i++){
        if(i*(i + 1)*(i + 2) == n)
            return 1;
    }
	return 0;
}

int main() {

	int n;
	scanf("%d", &n);

	if (eh_triangular(n))
		printf("SIM\n");
	else
		printf("NAO\n");

	return 0;
}
