/*Buscar Clube pelo ID:  Desenvolva um programa que permita ao usuário buscar um clube pelo ID. Se o clube for encontrado, exiba suas informações; caso contrário, informe que não foi encontrado.*/

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

Clube* buscarClubePorID(Clube clubes[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (clubes[i].id == id) {
            return &clubes[i];
        }
    }
    return NULL;
}

int main() {
    Clube clubes[MAX_CLUBES] = {
        {1, "Flamengo", 10, 5, 2, 30, 15},
        {2, "Vasco", 8, 7, 2, 20, 12},
        {3, "Botafogo", 5, 4, 8, 15, 20}
    };
    int n = 3;
    int id;

    printf("Informe o ID do clube para busca: ");
    scanf("%d", &id);

    Clube* clube = buscarClubePorID(clubes, n, id);
    if (clube != NULL) {
        printf("Clube encontrado:\n");
        printf("ID: %d\n", clube->id);
        printf("Nome: %s\n", clube->nome);
        printf("Vitórias: %d\n", clube->vitorias);
        printf("Empates: %d\n", clube->empates);
        printf("Derrotas: %d\n", clube->derrotas);
        printf("Gols Pró: %d\n", clube->gols_pro);
        printf("Gols Contra: %d\n", clube->gols_contra);
    } else {
        printf("Clube não encontrado.\n");
    }

    return 0;
}
