#include <stdio.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    float valor;
} Produto;

Produto* buscarProdutoPorID(Produto produtos[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (produtos[i].id == id) {
            return &produtos[i];
        }
    }
    return NULL;
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

    printf("Informe o ID do produto: ");
    scanf("%d", &id);

    Produto* produto = buscarProdutoPorID(produtos, n, id);
    if (produto != NULL) {
        printf("Produto encontrado:\n");
        printf("ID: %d\n", produto->id);
        printf("Nome: %s\n", produto->nome);
        printf("Valor: %.2f\n", produto->valor);
    } else {
        printf("Produto não encontrado.\n");
    }

    return 0;
}
