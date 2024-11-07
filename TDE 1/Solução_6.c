/*Cadastro de Clubes: Crie um programa que permita ao usuário cadastrar um número determinado de clubes (por exemplo, 10). Para cada clube, solicite que o usuário insira o ID, nome, vitórias, empates, derrotas, gols pró e gols contra. O programa deve calcular a pontuação de cada clube com base em suas vitórias, empates e derrotas. A pontuação deve ser calculada da seguinte forma: 3 pontos por vitória, 1 ponto por empate, 0 pontos por derrota. Exiba a pontuação total de cada clube.*/

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
    Clube clubes[MAX_CLUBES];
    int n;

    printf("Informe o número de clubes (máximo %d): ", MAX_CLUBES);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nCadastro do clube %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &clubes[i].id);
        printf("Nome: ");
        scanf(" %[^\n]s", clubes[i].nome);  // Lê string com espaços
        printf("Vitórias: ");
        scanf("%d", &clubes[i].vitorias);
        printf("Empates: ");
        scanf("%d", &clubes[i].empates);
        printf("Derrotas: ");
        scanf("%d", &clubes[i].derrotas);
        printf("Gols Pró: ");
        scanf("%d", &clubes[i].gols_pro);
        printf("Gols Contra: ");
        scanf("%d", &clubes[i].gols_contra);
    }

    printf("\nPontuação dos clubes:\n");
    for (int i = 0; i < n; i++) {
        int pontos = calcularPontuacao(clubes[i]);
        printf("Clube %s (ID: %d) - Pontuação: %d\n", clubes[i].nome, clubes[i].id, pontos);
    }

    return 0;
}
