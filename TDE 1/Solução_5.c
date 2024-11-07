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

void exibirProdutosAcimaDaMedia(Produto produtos[], int n, float media) {
    printf("Produtos com preço acima da média:\n");
    for (int i = 0; i < n; i++) {
        if (produtos[i].valor > media) {
            printf("ID: %d | Nome: %s | Preço: %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].valor);
        }
    }
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
    exibirProdutosAcimaDaMedia(produtos, n, media);

    return 0;
}
