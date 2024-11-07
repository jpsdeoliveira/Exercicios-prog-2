/*Exibir saldo de gols: Crie um programa que calcule o saldo de gols de todos os clubes e exiba o nome e o saldo de cada clube.*/

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

int calcularSaldoDeGols(Clube clube) {
    return clube.gols_pro - clube.gols_contra;
}

int main() {
    Clube clubes[MAX_CLUBES] = {
        {1, "Flamengo", 10, 5, 2, 30, 15},
        {2, "Vasco", 8, 7, 2, 20, 12},
        {3, "Botafogo", 5, 4, 8, 15, 20}
    };
    int n = 3;

    printf("\nSaldo de Gols dos Clubes:\n");
    for (int i = 0; i < n; i++) {
        int saldo = calcularSaldoDeGols(clubes[i]);
        printf("Clube %s (ID: %d) - Saldo de Gols: %d\n", clubes[i].nome, clubes[i].id, saldo);
    }

    return 0;
}
