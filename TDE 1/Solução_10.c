/*Exibir dados do melhor e do pior clube: Crie um programa que exiba os dados do clube campeão e do último colocado.*/

#include <stdio.h>

#define MAX_CLUBES 10

typedef struct {
    int id;
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int gols_pro;
    int gols_contra;
} Clube;

int calcularPontuacao(Clube clube) {
    return (clube.vitorias * 3) + (clube.empates * 1);
}

int main() {
    Clube clubes[MAX_CLUBES] = {
        {1, "Flamengo", 10, 5, 2, 30, 15},
        {2, "Vasco", 8, 7, 2, 20, 12},
        {3, "Botafogo", 5, 4, 8, 15, 20}
    };
    int n = 3;

    Clube* melhorClube = &clubes[0];
    Clube* piorClube = &clubes[0];

    for (int i = 1; i < n; i++) {
        int pontosAtual = calcularPontuacao(clubes[i]);
        int pontosMelhor = calcularPontuacao(*melhorClube);
        int pontosPior = calcularPontuacao(*piorClube);

        if (pontosAtual > pontosMelhor) {
            melhorClube = &clubes[i];
        }
        if (pontosAtual < pontosPior) {
            piorClube = &clubes[i];
        }
    }

    printf("\nMelhor Clube:\n");
    printf("Clube %s (ID: %d) - Pontuação: %d\n", melhorClube->nome, melhorClube->id, calcularPontuacao(*melhorClube));

    printf("\nPior Clube:\n");
    printf("Clube %s (ID: %d) - Pontuação: %d\n", piorClube->nome, piorClube->id, calcularPontuacao(*piorClube));

    return 0;
}
