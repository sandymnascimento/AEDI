#include <stdio.h>
#include <stdlib.h>

typedef struct Jogos Jogos;
struct Jogos{
    char time;
    int gols;
};

void disputas(Jogos *origem, Jogos *destino, int fase){
    int i;
    for(i = 0; i < fase; i++){
        if(origem[2*i].gols > origem[2*i+1].gols)
            destino[i].time = origem[2*i].time;
        else
            destino[i].time = origem[2*i+1].time;
    }
}
int main(int argc, char** argv) {
    int i, j = 65;
    Jogos oitavas[16];
    Jogos quartas[8];
    Jogos semi[4];
    Jogos final[2]; 
    
    for(i = 0; i < 16; i++){
        oitavas[i].time = j++;
        scanf("%d ", &oitavas[i].gols);
    }
    for(i = 0; i < 8; i++) scanf("%d ", &quartas[i].gols);
    for(i = 0; i < 4; i++) scanf("%d ", &semi[i].gols);
    scanf("%d %d", &final[0].gols, &final[1].gols);
    
    disputas(oitavas, quartas, 16);
    disputas(quartas, semi, 8);
    disputas(semi, final, 4);
    
    if(final[0].gols > final[1].gols) printf("%c\n", final[0].time);
    else printf("%c\n", final[1].time);
    
    return (EXIT_SUCCESS);
}