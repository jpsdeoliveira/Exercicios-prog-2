#include <stdio.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    float valor;
} Produto;

int atualizarValorProduto(Produto produtos[], int n, int id, float novoValor) {
    for (int i = 0; i < n; i++) {
        if (produtos[i].id == id) {
            produtos[i].valor = novoValor;
            return 1;
        }
    }
    return 0;
}

int main() {
    Produto produtos[MAX_PRODUTOS] = {
        {1, "Arroz", 10.5},
        {2, "Leite", 20.0},
        {3, "Biscoito", 30.0},
        {4, "Bala", 5.5}
    };
    int n = 4;
    int id;
    float novoValor;

    printf("Informe o ID do produto a ser atualizado: ");
    scanf("%d", &id);

    printf("Informe o novo valor: ");
    scanf("%f", &novoValor);

    if (atualizarValorProduto(produtos, n, id, novoValor)) {
        printf("Valor do produto atualizado com sucesso.\n");
    } else {
        printf("Produto não encontrado.\n");
    }

    return 0;
}
