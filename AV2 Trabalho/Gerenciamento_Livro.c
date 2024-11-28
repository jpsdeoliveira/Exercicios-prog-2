#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "livros.dat"

typedef struct {
    int codigo;
    char titulo[50];
    char autor[50];
    int ano;
} Livro;

void salvarLivro(Livro livro) {
    FILE *arquivo = fopen(ARQUIVO, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }
    fwrite(&livro, sizeof(Livro), 1, arquivo);
    fclose(arquivo);
}

void listarLivros() {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    Livro livro;
    printf("Catálogo de Livros:\n");
    printf("-----------------------------------------\n");
    while (fread(&livro, sizeof(Livro), 1, arquivo)) {
        printf("Código: %d\nTítulo: %s\nAutor: %s\nAno: %d\n\n",
               livro.codigo, livro.titulo, livro.autor, livro.ano);
    }
    fclose(arquivo);
}

Livro *buscarLivro(int codigo) {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        return NULL;
    }

    Livro *livro = (Livro *)malloc(sizeof(Livro));
    while (fread(livro, sizeof(Livro), 1, arquivo)) {
        if (livro->codigo == codigo) {
            fclose(arquivo);
            return livro;
        }
    }
    fclose(arquivo);
    free(livro);
    return NULL;
}

void atualizarArquivo(Livro *livros, int tamanho) {
    FILE *arquivo = fopen(ARQUIVO, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para atualizar.\n");
        return;
    }
    fwrite(livros, sizeof(Livro), tamanho, arquivo);
    fclose(arquivo);
}

void adicionarLivro() {
    Livro livro;
    printf("Código do livro: ");
    scanf("%d", &livro.codigo);
    printf("Título do livro: ");
    getchar(); 
    fgets(livro.titulo, 50, stdin);
    livro.titulo[strcspn(livro.titulo, "\n")] = '\0'; 
    printf("Autor do livro: ");
    fgets(livro.autor, 50, stdin);
    livro.autor[strcspn(livro.autor, "\n")] = '\0';
    printf("Ano de publicação: ");
    scanf("%d", &livro.ano);

    salvarLivro(livro);
    printf("Livro cadastrado com sucesso!\n");
}

void alterarLivro() {
    int codigo;
    printf("Código do livro a ser alterado: ");
    scanf("%d", &codigo);

    Livro *livro = buscarLivro(codigo);
    if (livro == NULL) {
        printf("Livro não encontrado.\n");
        return;
    }

    printf("Novo título (deixe em branco para não alterar): ");
    getchar(); 
    char novoTitulo[50];
    fgets(novoTitulo, 50, stdin);
    if (strlen(novoTitulo) > 1) {
        novoTitulo[strcspn(novoTitulo, "\n")] = '\0';
        strcpy(livro->titulo, novoTitulo);
    }

    printf("Novo autor (deixe em branco para não alterar): ");
    char novoAutor[50];
    fgets(novoAutor, 50, stdin);
    if (strlen(novoAutor) > 1) {
        novoAutor[strcspn(novoAutor, "\n")] = '\0';
        strcpy(livro->autor, novoAutor);
    }

    printf("Novo ano (0 para não alterar): ");
    int novoAno;
    scanf("%d", &novoAno);
    if (novoAno > 0) {
        livro->ano = novoAno;
    }

    FILE *arquivo = fopen(ARQUIVO, "rb");
    Livro livros[100];
    int tamanho = 0;

    while (fread(&livros[tamanho], sizeof(Livro), 1, arquivo)) {
        if (livros[tamanho].codigo == codigo) {
            livros[tamanho] = *livro;
        }
        tamanho++;
    }
    fclose(arquivo);

    atualizarArquivo(livros, tamanho);
    printf("Livro atualizado com sucesso!\n");
    free(livro);
}

void excluirLivro() {
    int codigo;
    printf("Código do livro a ser excluído: ");
    scanf("%d", &codigo);

    FILE *arquivo = fopen(ARQUIVO, "rb");
    Livro livros[100];
    int tamanho = 0;

    if (arquivo == NULL) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    while (fread(&livros[tamanho], sizeof(Livro), 1, arquivo)) {
        tamanho++;
    }
    fclose(arquivo);

    int encontrou = 0;
    for (int i = 0; i < tamanho; i++) {
        if (livros[i].codigo == codigo) {
            encontrou = 1;
            for (int j = i; j < tamanho - 1; j++) {
                livros[j] = livros[j + 1];
            }
            tamanho--;
            break;
        }
    }

    if (!encontrou) {
        printf("Livro não encontrado.\n");
        return;
    }

    atualizarArquivo(livros, tamanho);
    printf("Livro excluído com sucesso!\n");
}

void consultarLivro() {
    int codigo;
    printf("Código do livro: ");
    scanf("%d", &codigo);

    Livro *livro = buscarLivro(codigo);
    if (livro == NULL) {
        printf("Livro não encontrado.\n");
        return;
    }

    printf("Código: %d\nTítulo: %s\nAutor: %s\nAno: %d\n",
           livro->codigo, livro->titulo, livro->autor, livro->ano);
    free(livro);
}

int main() {
    int opcao;

    do {
        printf("\nGerenciamento de Livros\n");
        printf("1. Adicionar novo livro\n");
        printf("2. Alterar dados de um livro\n");
        printf("3. Excluir um livro\n");
        printf("4. Consultar um livro\n");
        printf("5. Listar todos os livros\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro();
                break;
            case 2:
                alterarLivro();
                break;
            case 3:
                excluirLivro();
                break;
            case 4:
                consultarLivro();
                break;
            case 5:
                listarLivros();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
