#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "funcionarios.dat"

typedef struct {
    int id;
    char nome[50];
    char cargo[30];
    int salario;
} Funcionario;

void salvarFuncionario(Funcionario funcionario) {
    FILE *arquivo = fopen(ARQUIVO, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }
    fwrite(&funcionario, sizeof(Funcionario), 1, arquivo);
    fclose(arquivo);
}

void listarFuncionarios() {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }

    Funcionario funcionario;
    printf("Lista de funcionários:\n");
    printf("-----------------------------------------\n");
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
        printf("ID: %d\nNome: %s\nCargo: %s\nSalário: R$%d\n\n",
               funcionario.id, funcionario.nome, funcionario.cargo, funcionario.salario);
    }
    fclose(arquivo);
}

Funcionario *buscarFuncionario(int id) {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        return NULL;
    }

    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));
    while (fread(funcionario, sizeof(Funcionario), 1, arquivo)) {
        if (funcionario->id == id) {
            fclose(arquivo);
            return funcionario;
        }
    }
    fclose(arquivo);
    free(funcionario);
    return NULL;
}

void atualizarArquivo(Funcionario *funcionarios, int tamanho) {
    FILE *arquivo = fopen(ARQUIVO, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para atualizar.\n");
        return;
    }
    fwrite(funcionarios, sizeof(Funcionario), tamanho, arquivo);
    fclose(arquivo);
}

void cadastrarFuncionario() {
    Funcionario funcionario;
    printf("ID: ");
    scanf("%d", &funcionario.id);
    printf("Nome: ");
    getchar();
    fgets(funcionario.nome, 50, stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0'; 
    printf("Cargo: ");
    fgets(funcionario.cargo, 30, stdin);
    funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0';
    printf("Salário: ");
    scanf("%d", &funcionario.salario);

    salvarFuncionario(funcionario);
    printf("Funcionário cadastrado com sucesso!\n");
}

void alterarFuncionario() {
    int id;
    printf("ID do funcionário a ser alterado: ");
    scanf("%d", &id);

    Funcionario *funcionario = buscarFuncionario(id);
    if (funcionario == NULL) {
        printf("Funcionário não encontrado.\n");
        return;
    }

    printf("Novo cargo (deixe em branco para não alterar): ");
    getchar(); 
    char novoCargo[30];
    fgets(novoCargo, 30, stdin);
    if (strlen(novoCargo) > 1) {
        novoCargo[strcspn(novoCargo, "\n")] = '\0';
        strcpy(funcionario->cargo, novoCargo);
    }

    printf("Novo salário (0 para não alterar): ");
    int novoSalario;
    scanf("%d", &novoSalario);
    if (novoSalario > 0) {
        funcionario->salario = novoSalario;
    }

    FILE *arquivo = fopen(ARQUIVO, "rb");
    Funcionario funcionarios[100];
    int tamanho = 0;

    while (fread(&funcionarios[tamanho], sizeof(Funcionario), 1, arquivo)) {
        if (funcionarios[tamanho].id == id) {
            funcionarios[tamanho] = *funcionario;
        }
        tamanho++;
    }
    fclose(arquivo);

    atualizarArquivo(funcionarios, tamanho);
    printf("Funcionário atualizado com sucesso!\n");
    free(funcionario);
}

void excluirFuncionario() {
    int id;
    printf("ID do funcionário a ser excluído: ");
    scanf("%d", &id);

    FILE *arquivo = fopen(ARQUIVO, "rb");
    Funcionario funcionarios[100];
    int tamanho = 0;

    if (arquivo == NULL) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }

    while (fread(&funcionarios[tamanho], sizeof(Funcionario), 1, arquivo)) {
        tamanho++;
    }
    fclose(arquivo);

    int encontrou = 0;
    for (int i = 0; i < tamanho; i++) {
        if (funcionarios[i].id == id) {
            encontrou = 1;
            for (int j = i; j < tamanho - 1; j++) {
                funcionarios[j] = funcionarios[j + 1];
            }
            tamanho--;
            break;
        }
    }

    if (!encontrou) {
        printf("Funcionário não encontrado.\n");
        return;
    }

    atualizarArquivo(funcionarios, tamanho);
    printf("Funcionário excluído com sucesso!\n");
}

void consultarFuncionario() {
    int id;
    printf("ID do funcionário: ");
    scanf("%d", &id);

    Funcionario *funcionario = buscarFuncionario(id);
    if (funcionario == NULL) {
        printf("Funcionário não encontrado.\n");
        return;
    }

    printf("ID: %d\nNome: %s\nCargo: %s\nSalário: R$%d\n",
           funcionario->id, funcionario->nome, funcionario->cargo, funcionario->salario);
    free(funcionario);
}

int main() {
    int opcao;

    do {
        printf("\nGerenciamento de Funcionários\n");
        printf("1. Cadastrar novo funcionário\n");
        printf("2. Alterar dados de funcionário\n");
        printf("3. Excluir funcionário\n");
        printf("4. Consultar funcionário\n");
        printf("5. Listar todos os funcionários\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFuncionario();
                break;
            case 2:
                alterarFuncionario();
                break;
            case 3:
                excluirFuncionario();
                break;
            case 4:
                consultarFuncionario();
                break;
            case 5:
                listarFuncionarios();
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
