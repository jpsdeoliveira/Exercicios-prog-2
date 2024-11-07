/*Calcular Média de Preços: Implemente um programa que calcule e retorne a média dos preços dos produtos.*/

#include <stdio.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    float valor;
} Produto;

float calcularMediaPreco(Produto produtos[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += produtos[i].valor;
    }
    return soma / n;
}

int main() {
    Produto produtos[MAX_PRODUTOS] = {
        {1, "Arroz", 10.5},
        {2, "Leite", 20.0},
        {3, "Biscoito", 30.0},
        {4, "Bala", 5.5}
    };
    int n = 4;

    float media = calcularMediaPreco(produtos, n);
    printf("A média dos preços dos produtos é: %.2f\n", media);

    return 0;
}
