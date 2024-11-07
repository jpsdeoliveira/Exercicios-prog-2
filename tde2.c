#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

    /*Exercício 1: Crie um programa que leia uma string e exiba seu conteúdo. Em seguida, exiba o comprimento da string usando a função strlen().

    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    printf("String digitada: %s\n", str);
    printf("Comprimento da string: %lu\n", strlen(str));*/

    /*Exercício 2: Implemente um programa que leia duas strings do usuário e verifique se elas são iguais. Exiba uma mensagem informando se as strings são iguais ou diferentes. Use a função strcmp() para a comparação.

    char str1[100], str2[100];

    printf("Digite a primeira string: ");
    scanf("%s", str1);
    printf("Digite a segunda string: ");
    scanf("%s", str2);

    if (strcmp(str1, str2) == 0){
        printf("As strings são iguais.\n");
    }else{
        printf("As strings são diferentes.\n");
    }*/
    
    /*Exercício 3: Escreva um programa que leia uma string do usuário e exiba cada caractere da string em uma linha separada.

    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++){
        printf("%c\n", str[i]);
    }*/
    
    /*Exercício 4: Implemente um programa que leia uma string e verifique quantas vezes o caractere 'a' aparece nela. Exiba o total de ocorrências.

    char str[100];
    int count = 0;

    printf("Digite uma string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == 'a'){
            count++;
        }
    }

    printf("O caractere 'a' aparece %d vezes na string.\n", count);*/

    /*Exercício 5: Crie um programa que leia uma string e a copie para outra variável usando a função strcpy(). Exiba as duas strings para verificar se a cópia foi bem-sucedida.

    char str1[100], str2[100];

    printf("Digite uma string: ");
    scanf("%s", str1);
    
    strcpy(str2, str1);

    printf("String original: %s\n", str1);
    printf("String copiada: %s\n", str2);*/

    /*Exercício 6: Implemente um programa que leia duas strings e as concatene em uma nova string. Use a função strcat() para realizar a concatenação e exiba o resultado.

    char str1[100], str2[100], str3[200];

    printf("Digite a primeira string: ");
    scanf("%s", str1);
    printf("Digite a segunda string: ");
    scanf("%s", str2);

    strcpy(str3, str1);
    strcat(str3, str2);

    printf("String concatenada: %s\n", str3);*/

    /*Exercício 7: Escreva um programa que leia uma string e substitua todos os caracteres minúsculos por maiúsculos. Utilize a função toupper() da biblioteca <ctype.h> para auxiliar na conversão.

    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++){
        str[i] = toupper(str[i]);
    }

    printf("String em maiúsculas: %s\n", str);*/

    /*Exercício 8: Implemente um programa que leia uma string e conte o número de vogais presentes nela. Considere as vogais 'a', 'e', 'i', 'o', 'u' (maiúsculas e minúsculas).

    char str[100];
    int count = 0;

    printf("Digite uma string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            count++;
        }
    }

    printf("O número de vogais na string é: %d\n", count);*/

    /*Exercício 9: Crie um programa que leia uma string e conte o número de espaços em branco nela. Exiba o total de espaços.

    char str[100];
    int count = 0;

    printf("Digite uma string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ' '){
            count++;
        }
    }

    printf("O número de espaços em branco na string é: %d\n", count);*/

    /*Exercício 10: Escreva um programa que leia uma string e conte o número de letras, dígitos e caracteres especiais presentes nela. Use as funções isalpha() e isdigit() da biblioteca <ctype.h> para verificar o tipo de cada caractere.

    char str[100];
    int countLetras = 0, countDigitos = 0, countEspeciais = 0;

    printf("Digite uma string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++){
        if (isalpha(str[i])){
            countLetras++;
        }
    }

    for (int i = 0; str[i] != '\0'; i++){
        if (isdigit(str[i])){
            countDigitos++;
        }
    }

    for (int i = 0; str[i] != '\0'; i++){
        if (!isalpha(str[i]) && !isdigit(str[i])){
            countEspeciais++;
        }
    }

    printf("O número de letras na string é: %d\n", countLetras);
    printf("O número de dígitos na string é: %d\n", countDigitos);
    printf("O número de caracteres especiais na string é: %d\n", countEspeciais);*/
