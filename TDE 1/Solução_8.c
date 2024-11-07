/*Exibir Clubes com Gols Pró Acima da Média: Crie um programa que calcule a média de gols pró de todos os clubes e exiba apenas os clubes que têm um número de gols pró superior a essa média.*/

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

float calcularMediaGolsPro(Clube clubes[], int n) {
    int somaGolsPro = 0;
    for (int i = 0; i < n; i++) {
        somaGolsPro += clubes[i].gols_pro;
    }
    return (float)somaGolsPro / n;
}

void exibirClubesAcimaDaMedia(Clube clubes[], int n, float media) {
    printf("\nClubes com gols pró acima da média (%.2f):\n", media);
    for (int i = 0; i < n; i++) {
        if (clubes[i].gols_pro > media) {
            printf("Clube %s (ID: %d) - Gols Pró: %d\n", clubes[i].nome, clubes[i].id, clubes[i].gols_pro);
        }
    }
}

int main() {
    Clube clubes[MAX_CLUBES] = {
        {1, "Flamengo", 10, 5, 2, 30, 15},
        {2, "Vasco", 8, 7, 2, 20, 12},
        {3, "Botafogo", 5, 4, 8, 15, 20}
    };
    int n = 3;

    float media = calcularMediaGolsPro(clubes, n);
    exibirClubesAcimaDaMedia(clubes, n, media);

    return 0;
}
