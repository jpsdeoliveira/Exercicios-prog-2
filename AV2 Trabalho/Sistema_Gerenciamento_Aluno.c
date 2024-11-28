#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[50];
    char curso[30];
    int idade;
} Aluno;

void incluirAluno(FILE *arquivo) {
    Aluno aluno;
    printf("Digite o número de matrícula: ");
    scanf("%d", &aluno.matricula);
    getchar(); 

    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';  

    printf("Digite o curso: ");
    fgets(aluno.curso, sizeof(aluno.curso), stdin);
    aluno.curso[strcspn(aluno.curso, "\n")] = '\0';  

    printf("Digite a idade do aluno: ");
    scanf("%d", &aluno.idade);

    fseek(arquivo, 0, SEEK_END); 
    fwrite(&aluno, sizeof(Aluno), 1, arquivo);
    printf("Aluno incluído com sucesso!\n");
}

void alterarAluno(FILE *arquivo) {
    int matricula;
    Aluno aluno;
    int encontrado = 0;

    printf("Digite o número de matrícula do aluno que deseja alterar: ");
    scanf("%d", &matricula);
    getchar(); 

    fseek(arquivo, 0, SEEK_SET);
    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        if (aluno.matricula == matricula) {
            encontrado = 1;
            printf("Aluno encontrado!\n");
            printf("Digite o novo nome: ");
            fgets(aluno.nome, sizeof(aluno.nome), stdin);
            aluno.nome[strcspn(aluno.nome, "\n")] = '\0'; 

            printf("Digite o novo curso: ");
            fgets(aluno.curso, sizeof(aluno.curso), stdin);
            aluno.curso[strcspn(aluno.curso, "\n")] = '\0'; 

            printf("Digite a nova idade: ");
            scanf("%d", &aluno.idade);

            fseek(arquivo, -sizeof(Aluno), SEEK_CUR);
            fwrite(&aluno, sizeof(Aluno), 1, arquivo);
            printf("Aluno alterado com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno não encontrado!\n");
    }
}

void excluirAluno(FILE *arquivo) {
    int matricula;
    Aluno aluno;
    FILE *tempArquivo;
    int encontrado = 0;

    printf("Digite o número de matrícula do aluno que deseja excluir: ");
    scanf("%d", &matricula);

    tempArquivo = fopen("temp.dat", "wb");
    if (tempArquivo == NULL) {
        printf("Erro ao abrir o arquivo temporário.\n");
        return;
    }

    fseek(arquivo, 0, SEEK_SET);
    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        if (aluno.matricula != matricula) {
            fwrite(&aluno, sizeof(Aluno), 1, tempArquivo);  
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(tempArquivo);

    if (encontrado) {
        remove("alunos.dat"); 
        rename("temp.dat", "alunos.dat");
        printf("Aluno excluído com sucesso!\n");
    } else {
        remove("temp.dat"); 
        printf("Aluno não encontrado!\n");
    }
}

void consultarAluno(FILE *arquivo) {
    int matricula;
    Aluno aluno;
    int encontrado = 0;

    printf("Digite o número de matrícula do aluno que deseja consultar: ");
    scanf("%d", &matricula);

    fseek(arquivo, 0, SEEK_SET);
    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        if (aluno.matricula == matricula) {
            printf("Aluno encontrado!\n");
            printf("Matrícula: %d\n", aluno.matricula);
            printf("Nome: %s\n", aluno.nome);
            printf("Curso: %s\n", aluno.curso);
            printf("Idade: %d\n", aluno.idade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno não encontrado!\n");
    }
}

void listarAlunos(FILE *arquivo) {
    Aluno aluno;

    fseek(arquivo, 0, SEEK_SET);
    printf("Lista de alunos cadastrados:\n");
    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        printf("Matrícula: %d\n", aluno.matricula);
        printf("Nome: %s\n", aluno.nome);
        printf("Curso: %s\n", aluno.curso);
        printf("Idade: %d\n", aluno.idade);
        printf("-----------------------------\n");
    }
}

int main() {
    FILE *arquivo;
    int opcao;

    arquivo = fopen("alunos.dat", "rb+");
    if (arquivo == NULL) {
        arquivo = fopen("alunos.dat", "wb+");  // Cria o arquivo se não existir
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. Incluir novo aluno\n");
        printf("2. Alterar informações de um aluno\n");
        printf("3. Excluir aluno\n");
        printf("4. Consultar aluno\n");
        printf("5. Listar todos os alunos\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                incluirAluno(arquivo);
                break;
            case 2:
                alterarAluno(arquivo);
                break;
            case 3:
                excluirAluno(arquivo);
                break;
            case 4:
                consultarAluno(arquivo);
                break;
            case 5:
                listarAlunos(arquivo);
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6);

    fclose(arquivo);
    return 0;
