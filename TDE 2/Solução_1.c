/*Exercício 1: Crie um programa que leia uma string e exiba seu conteúdo. Em seguida, exiba o comprimento da string usando a função strlen().*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    printf("String digitada: %s\n", str);
    printf("Comprimento da string: %lu\n", strlen(str));
    
    return 0;
}
