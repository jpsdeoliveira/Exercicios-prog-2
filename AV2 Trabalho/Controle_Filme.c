#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "filmes.dat"

typedef struct {
    int id;
    char titulo[50];
    char genero[20];
    int ano;
} Filme;

void salvarFilme(Filme filme) {
    FILE *arquivo = fopen(ARQUIVO, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }
    fwrite(&filme, sizeof(Filme), 1, arquivo);
    fclose(arquivo);
}

void listarFilmes() {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        printf("Nenhum filme cadastrado.\n");
        return;
    }

    Filme filme;
    printf("Acervo de Filmes:\n");
    printf("-----------------------------------------\n");
    while (fread(&filme, sizeof(Filme), 1, arquivo)) {
        printf("ID: %d\nTítulo: %s\nGênero: %s\nAno: %d\n\n",
               filme.id, filme.titulo, filme.genero, filme.ano);
    }
    fclose(arquivo);
}

Filme *buscarFilmePorId(int id) {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        return NULL;
    }

    Filme *filme = (Filme *)malloc(sizeof(Filme));
    while (fread(filme, sizeof(Filme), 1, arquivo)) {
        if (filme->id == id) {
            fclose(arquivo);
            return filme;
        }
    }
    fclose(arquivo);
    free(filme);
    return NULL;
}

void atualizarArquivo(Filme *filmes, int tamanho) {
    FILE *arquivo = fopen(ARQUIVO, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para atualizar.\n");
        return;
    }
    fwrite(filmes, sizeof(Filme), tamanho, arquivo);
    fclose(arquivo);
}

void adicionarFilme() {
    Filme filme;
    printf("ID do filme: ");
    scanf("%d", &filme.id);
    printf("Título do filme: ");
    getchar(); 
    fgets(filme.titulo, 50, stdin);
    filme.titulo[strcspn(filme.titulo, "\n")] = '\0'; 
    printf("Gênero do filme: ");
    fgets(filme.genero, 20, stdin);
    filme.genero[strcspn(filme.genero, "\n")] = '\0'; 
    printf("Ano de lançamento: ");
    scanf("%d", &filme.ano);

    salvarFilme(filme);
    printf("Filme cadastrado com sucesso!\n");
}

void alterarFilme() {
    int id;
    printf("ID do filme a ser alterado: ");
    scanf("%d", &id);

    Filme *filme = buscarFilmePorId(id);
    if (filme == NULL) {
        printf("Filme não encontrado.\n");
        return;
    }

    printf("Novo título (deixe em branco para não alterar): ");
    getchar(); 
    char novoTitulo[50];
    fgets(novoTitulo, 50, stdin);
    if (strlen(novoTitulo) > 1) {
        novoTitulo[strcspn(novoTitulo, "\n")] = '\0';
        strcpy(filme->titulo, novoTitulo);
    }

    printf("Novo gênero (deixe em branco para não alterar): ");
    char novoGenero[20];
    fgets(novoGenero, 20, stdin);
    if (strlen(novoGenero) > 1) {
        novoGenero[strcspn(novoGenero, "\n")] = '\0';
        strcpy(filme->genero, novoGenero);
    }

    printf("Novo ano (0 para não alterar): ");
    int novoAno;
    scanf("%d", &novoAno);
    if (novoAno > 0) {
        filme->ano = novoAno;
    }

    FILE *arquivo = fopen(ARQUIVO, "rb");
    Filme filmes[100];
    int tamanho = 0;

    while (fread(&filmes[tamanho], sizeof(Filme), 1, arquivo)) {
        if (filmes[tamanho].id == id) {
            filmes[tamanho] = *filme;
        }
        tamanho++;
    }
    fclose(arquivo);

    atualizarArquivo(filmes, tamanho);
    printf("Filme atualizado com sucesso!\n");
    free(filme);
}

void excluirFilme() {
    int id;
    printf("ID do filme a ser excluído: ");
    scanf("%d", &id);

    FILE *arquivo = fopen(ARQUIVO, "rb");
    Filme filmes[100];
    int tamanho = 0;

    if (arquivo == NULL) {
        printf("Nenhum filme cadastrado.\n");
        return;
    }

    while (fread(&filmes[tamanho], sizeof(Filme), 1, arquivo)) {
        tamanho++;
    }
    fclose(arquivo);

    int encontrou = 0;
    for (int i = 0; i < tamanho; i++) {
        if (filmes[i].id == id) {
            encontrou = 1;
            for (int j = i; j < tamanho - 1; j++) {
                filmes[j] = filmes[j + 1];
            }
            tamanho--;
            break;
        }
    }

    if (!encontrou) {
        printf("Filme não encontrado.\n");
        return;
    }

    atualizarArquivo(filmes, tamanho);
    printf("Filme excluído com sucesso!\n");
}

void consultarFilme() {
    int id;
    printf("ID do filme: ");
    scanf("%d", &id);

    Filme *filme = buscarFilmePorId(id);
    if (filme == NULL) {
        printf("Filme não encontrado.\n");
        return;
    }

    printf("ID: %d\nTítulo: %s\nGênero: %s\nAno: %d\n",
           filme->id, filme->titulo, filme->genero, filme->ano);
    free(filme);
}

int main() {
    int opcao;

    do {
        printf("\nControle de Filmes\n");
        printf("1. Adicionar novo filme\n");
        printf("2. Alterar dados de um filme\n");
        printf("3. Excluir um filme\n");
        printf("4. Consultar filme pelo ID\n");
        printf("5. Listar todos os filmes\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarFilme();
                break;
            case 2:
                alterarFilme();
                break;
            case 3:
                excluirFilme();
                break;
            case 4:
                consultarFilme();
                break;
            case 5:
                listarFilmes();
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
