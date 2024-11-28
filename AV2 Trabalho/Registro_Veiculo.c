#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "veiculos.dat"

typedef struct {
    int id;
    char modelo[50];
    char placa[10];
    int ano;
} Veiculo;

void salvarVeiculo(Veiculo veiculo) {
    FILE *arquivo = fopen(ARQUIVO, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }
    fwrite(&veiculo, sizeof(Veiculo), 1, arquivo);
    fclose(arquivo);
}

void listarVeiculos() {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        printf("Nenhum veículo cadastrado.\n");
        return;
    }

    Veiculo veiculo;
    printf("Registro de Veículos:\n");
    printf("-----------------------------------------\n");
    while (fread(&veiculo, sizeof(Veiculo), 1, arquivo)) {
        printf("ID: %d\nModelo: %s\nPlaca: %s\nAno: %d\n\n",
               veiculo.id, veiculo.modelo, veiculo.placa, veiculo.ano);
    }
    fclose(arquivo);
}

Veiculo *buscarVeiculoPorPlaca(char *placa) {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        return NULL;
    }

    Veiculo *veiculo = (Veiculo *)malloc(sizeof(Veiculo));
    while (fread(veiculo, sizeof(Veiculo), 1, arquivo)) {
        if (strcmp(veiculo->placa, placa) == 0) {
            fclose(arquivo);
            return veiculo;
        }
    }
    fclose(arquivo);
    free(veiculo);
    return NULL;
}

Veiculo *buscarVeiculoPorId(int id) {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        return NULL;
    }

    Veiculo *veiculo = (Veiculo *)malloc(sizeof(Veiculo));
    while (fread(veiculo, sizeof(Veiculo), 1, arquivo)) {
        if (veiculo->id == id) {
            fclose(arquivo);
            return veiculo;
        }
    }
    fclose(arquivo);
    free(veiculo);
    return NULL;
}

void atualizarArquivo(Veiculo *veiculos, int tamanho) {
    FILE *arquivo = fopen(ARQUIVO, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para atualizar.\n");
        return;
    }
    fwrite(veiculos, sizeof(Veiculo), tamanho, arquivo);
    fclose(arquivo);
}

void adicionarVeiculo() {
    Veiculo veiculo;
    printf("ID do veículo: ");
    scanf("%d", &veiculo.id);
    printf("Modelo do veículo: ");
    getchar(); 
    fgets(veiculo.modelo, 50, stdin);
    veiculo.modelo[strcspn(veiculo.modelo, "\n")] = '\0'; 
    printf("Placa do veículo: ");
    fgets(veiculo.placa, 10, stdin);
    veiculo.placa[strcspn(veiculo.placa, "\n")] = '\0'; 
    printf("Ano de fabricação: ");
    scanf("%d", &veiculo.ano);

    salvarVeiculo(veiculo);
    printf("Veículo cadastrado com sucesso!\n");
}

void alterarVeiculo() {
    int id;
    printf("ID do veículo a ser alterado: ");
    scanf("%d", &id);

    Veiculo *veiculo = buscarVeiculoPorId(id);
    if (veiculo == NULL) {
        printf("Veículo não encontrado.\n");
        return;
    }

    printf("Novo modelo (deixe em branco para não alterar): ");
    getchar(); 
    char novoModelo[50];
    fgets(novoModelo, 50, stdin);
    if (strlen(novoModelo) > 1) {
        novoModelo[strcspn(novoModelo, "\n")] = '\0';
        strcpy(veiculo->modelo, novoModelo);
    }

    printf("Nova placa (deixe em branco para não alterar): ");
    char novaPlaca[10];
    fgets(novaPlaca, 10, stdin);
    if (strlen(novaPlaca) > 1) {
        novaPlaca[strcspn(novaPlaca, "\n")] = '\0';
        strcpy(veiculo->placa, novaPlaca);
    }

    printf("Novo ano (0 para não alterar): ");
    int novoAno;
    scanf("%d", &novoAno);
    if (novoAno > 0) {
        veiculo->ano = novoAno;
    }

    FILE *arquivo = fopen(ARQUIVO, "rb");
    Veiculo veiculos[100];
    int tamanho = 0;

    while (fread(&veiculos[tamanho], sizeof(Veiculo), 1, arquivo)) {
        if (veiculos[tamanho].id == id) {
            veiculos[tamanho] = *veiculo;
        }
        tamanho++;
    }
    fclose(arquivo);

    atualizarArquivo(veiculos, tamanho);
    printf("Veículo atualizado com sucesso!\n");
    free(veiculo);
}

void excluirVeiculo() {
    int id;
    printf("ID do veículo a ser excluído: ");
    scanf("%d", &id);

    FILE *arquivo = fopen(ARQUIVO, "rb");
    Veiculo veiculos[100];
    int tamanho = 0;

    if (arquivo == NULL) {
        printf("Nenhum veículo cadastrado.\n");
        return;
    }

    while (fread(&veiculos[tamanho], sizeof(Veiculo), 1, arquivo)) {
        tamanho++;
    }
    fclose(arquivo);

    int encontrou = 0;
    for (int i = 0; i < tamanho; i++) {
        if (veiculos[i].id == id) {
            encontrou = 1;
            for (int j = i; j < tamanho - 1; j++) {
                veiculos[j] = veiculos[j + 1];
            }
            tamanho--;
            break;
        }
    }

    if (!encontrou) {
        printf("Veículo não encontrado.\n");
        return;
    }

    atualizarArquivo(veiculos, tamanho);
    printf("Veículo excluído com sucesso!\n");
}

void consultarVeiculo() {
    char placa[10];
    printf("Placa do veículo: ");
    getchar(); 
    fgets(placa, 10, stdin);
    placa[strcspn(placa, "\n")] = '\0';

    Veiculo *veiculo = buscarVeiculoPorPlaca(placa);
    if (veiculo == NULL) {
        printf("Veículo não encontrado.\n");
        return;
    }

    printf("ID: %d\nModelo: %s\nPlaca: %s\nAno: %d\n",
           veiculo->id, veiculo->modelo, veiculo->placa, veiculo->ano);
    free(veiculo);
}

int main() {
    int opcao;

    do {
        printf("\nGerenciamento de Veículos\n");
        printf("1. Adicionar novo veículo\n");
        printf("2. Alterar dados de um veículo\n");
        printf("3. Excluir um veículo\n");
        printf("4. Consultar veículo pela placa\n");
        printf("5. Listar todos os veículos\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarVeiculo();
                break;
            case 2:
                alterarVeiculo();
                break;
            case 3:
                excluirVeiculo();
                break;
            case 4:
                consultarVeiculo();
                break;
            case 5:
                listarVeiculos();
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
