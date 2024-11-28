#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "cidades.txt"
#define TEMP "temp.txt"

typedef struct {
    int codigo;
    char nome[50];
    char estado[30];
    int populacao;
} Cidade;

void salvarCidade(Cidade cidade) {
    FILE *arquivo = fopen(ARQUIVO, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }
    fprintf(arquivo, "%d,%s,%s,%d\n", cidade.codigo, cidade.nome, cidade.estado, cidade.populacao);
    fclose(arquivo);
}

void listarCidades() {
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) {
        printf("Nenhuma cidade cadastrada.\n");
        return;
    }

    char linha[200];
    printf("Cidades cadastradas:\n");
    printf("-----------------------------------------\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        int codigo, populacao;
        char nome[50], estado[30];

        sscanf(linha, "%d,%49[^,],%29[^,],%d", &codigo, nome, estado, &populacao);
        printf("Código: %d\nNome: %s\nEstado: %s\nPopulação: %d\n\n", codigo, nome, estado, populacao);
    }
    fclose(arquivo);
}

Cidade *buscarCidadePorCodigo(int codigo) {
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) {
        return NULL;
    }

    char linha[200];
    Cidade *cidade = (Cidade *)malloc(sizeof(Cidade));
    while (fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%d,%49[^,],%29[^,],%d", &cidade->codigo, cidade->nome, cidade->estado, &cidade->populacao);
        if (cidade->codigo == codigo) {
            fclose(arquivo);
            return cidade;
        }
    }
    fclose(arquivo);
    free(cidade);
    return NULL;
}

void atualizarArquivo(FILE *arquivoTemp, int codigoExcluir, Cidade *cidadeAlterada) {
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    char linha[200];
    while (fgets(linha, sizeof(linha), arquivo)) {
        Cidade cidadeAtual;
        sscanf(linha, "%d,%49[^,],%29[^,],%d", &cidadeAtual.codigo, cidadeAtual.nome, cidadeAtual.estado, &cidadeAtual.populacao);

        if (cidadeAtual.codigo == codigoExcluir) {
            if (cidadeAlterada != NULL) {
                fprintf(arquivoTemp, "%d,%s,%s,%d\n", cidadeAlterada->codigo, cidadeAlterada->nome, cidadeAlterada->estado, cidadeAlterada->populacao);
            }
        } else {
            fprintf(arquivoTemp, "%s", linha);
        }
    }

    fclose(arquivo);
}

void incluirCidade() {
    Cidade cidade;
    printf("Código da cidade: ");
    scanf("%d", &cidade.codigo);
    printf("Nome da cidade: ");
    getchar();
    fgets(cidade.nome, 50, stdin);
    cidade.nome[strcspn(cidade.nome, "\n")] = '\0'; 
    printf("Estado: ");
    fgets(cidade.estado, 30, stdin);
    cidade.estado[strcspn(cidade.estado, "\n")] = '\0'; 
    printf("População: ");
    scanf("%d", &cidade.populacao);

    salvarCidade(cidade);
    printf("Cidade cadastrada com sucesso!\n");
}

void alterarCidade() {
    int codigo;
    printf("Código da cidade a ser alterada: ");
    scanf("%d", &codigo);

    Cidade *cidade = buscarCidadePorCodigo(codigo);
    if (cidade == NULL) {
        printf("Cidade não encontrada.\n");
        return;
    }

    printf("Novo nome (deixe em branco para não alterar): ");
    getchar();
    char novoNome[50];
    fgets(novoNome, 50, stdin);
    if (strlen(novoNome) > 1) {
        novoNome[strcspn(novoNome, "\n")] = '\0';
        strcpy(cidade->nome, novoNome);
    }

    printf("Novo estado (deixe em branco para não alterar): ");
    char novoEstado[30];
    fgets(novoEstado, 30, stdin);
    if (strlen(novoEstado) > 1) {
        novoEstado[strcspn(novoEstado, "\n")] = '\0';
        strcpy(cidade->estado, novoEstado);
    }

    printf("Nova população (0 para não alterar): ");
    int novaPopulacao;
    scanf("%d", &novaPopulacao);
    if (novaPopulacao > 0) {
        cidade->populacao = novaPopulacao;
    }

    FILE *arquivoTemp = fopen(TEMP, "w");
    atualizarArquivo(arquivoTemp, codigo, cidade);
    fclose(arquivoTemp);

    remove(ARQUIVO);
    rename(TEMP, ARQUIVO);

    printf("Cidade atualizada com sucesso!\n");
    free(cidade);
}

void excluirCidade() {
    int codigo;
    printf("Código da cidade a ser excluída: ");
    scanf("%d", &codigo);

    FILE *arquivoTemp = fopen(TEMP, "w");
    atualizarArquivo(arquivoTemp, codigo, NULL);
    fclose(arquivoTemp);

    remove(ARQUIVO);
    rename(TEMP, ARQUIVO);

    printf("Cidade excluída com sucesso!\n");
}

void consultarCidade() {
    int codigo;
    printf("Código da cidade: ");
    scanf("%d", &codigo);

    Cidade *cidade = buscarCidadePorCodigo(codigo);
    if (cidade == NULL) {
        printf("Cidade não encontrada.\n");
        return;
    }

    printf("Código: %d\nNome: %s\nEstado: %s\nPopulação: %d\n",
           cidade->codigo, cidade->nome, cidade->estado, cidade->populacao);
    free(cidade);
}

int main() {
    int opcao;

    do {
        printf("\nCadastro de Cidades\n");
        printf("1. Incluir nova cidade\n");
        printf("2. Alterar dados de uma cidade\n");
        printf("3. Excluir uma cidade\n");
        printf("4. Consultar cidade pelo código\n");
        printf("5. Listar todas as cidades\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirCidade();
                break;
            case 2:
                alterarCidade();
                break;
            case 3:
                excluirCidade();
                break;
            case 4:
                consultarCidade();
                break;
            case 5:
                listarCidades();
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
