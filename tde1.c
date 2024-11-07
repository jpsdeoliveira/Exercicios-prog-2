#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    float valor;
} Produto;

Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

void adicionarProduto(int id, const char* nome, float valor) {
    if (totalProdutos < MAX_PRODUTOS) {
        produtos[totalProdutos].id = id;
        strcpy(produtos[totalProdutos].nome, nome);
        produtos[totalProdutos].valor = valor;
        totalProdutos++;
    } else {
        printf("Limite de produtos atingido.\n");
    }
}

int contarProdutosAbaixoDe(float valor) {
    int count = 0;
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].valor < valor) {
            count++;
        }
    }
    return count;
}

void buscarProdutoPorID(int id) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == id) {
            printf("Produto encontrado: ID: %d, Nome: %s, Valor: %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].valor);
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

void atualizarValorProduto(int id, float novoValor) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == id) {
            produtos[i].valor = novoValor;
            printf("Valor do produto ID %d atualizado para %.2f\n", id, novoValor);
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

float calcularMediaPrecos() {
    if (totalProdutos == 0) return 0;
    float soma = 0;
    for (int i = 0; i < totalProdutos; i++) {
        soma += produtos[i].valor;
    }
    return soma / totalProdutos;
}

void exibirProdutosAcimaDaMedia() {
    float media = calcularMediaPrecos();
    printf("Produtos acima da média (%.2f):\n", media);
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].valor > media) {
            printf("ID: %d, Nome: %s, Valor: %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].valor);
        }
    }
}

int main() {
    adicionarProduto(1, "PS5", 5000.00);
    adicionarProduto(2, "Tv 50p", 2500.00);
    adicionarProduto(3, "Sofá", 900.00);
    adicionarProduto(4, "Pc", 1222.00);

    float valorLimite;
    printf("Digite o valor limite: ");
    scanf("%f", &valorLimite);
    printf("Produtos abaixo de %.2f: %d\n", valorLimite, contarProdutosAbaixoDe(valorLimite));

    int idBuscado;
    printf("Digite o ID do produto a buscar: ");
    scanf("%d", &idBuscado);
    buscarProdutoPorID(idBuscado);

    int idAtualizar;
    float novoValor;
    printf("Digite o ID do produto para atualizar o valor: ");
    scanf("%d", &idAtualizar);
    printf("Digite o novo valor: ");
    scanf("%f", &novoValor);
    atualizarValorProduto(idAtualizar, novoValor);

    exibirProdutosAcimaDaMedia();

    return 0;
}
