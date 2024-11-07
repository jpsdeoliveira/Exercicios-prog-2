#include <stdio.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    float valor;
} Produto;

int contarProdutosAbaixoDeValor(Produto produtos[], int n, float limite) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (produtos[i].valor < limite) {
            count++;
        }
    }
    return count;
}

int main() {
    Produto produtos[MAX_PRODUTOS] = {
        {1, "Produto 1", 10.5},
        {2, "Produto 2", 20.0},
        {3, "Produto 3", 30.0},
        {4, "Produto 4", 5.5}
    };
    int n = 4;
    float limite;
    
    printf("Informe o valor limite: ");
    scanf("%f", &limite);

    int resultado = contarProdutosAbaixoDeValor(produtos, n, limite);
    printf("Quantidade de produtos abaixo de %.2f: %d\n", limite, resultado);

    return 0;
}

