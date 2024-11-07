/*Cadastro de Clubes: Crie um programa que permita ao usuário cadastrar um número determinado de clubes (por exemplo, 10). Para cada clube, solicite que o usuário insira o ID, nome, vitórias, empates, derrotas, gols pró e gols contra. O programa deve calcular a pontuação de cada clube com base em suas vitórias, empates e derrotas. A pontuação deve ser calculada da seguinte forma: 3 pontos por vitória, 1 ponto por empate, 0 pontos por derrota. Exiba a pontuação total de cada clube./*

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
