/*Exercício 3: Escreva um programa que leia uma string do usuário e exiba cada caractere da string em uma linha separada.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
  
  char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++){
        printf("%c\n", str[i]);
    }

    return 0;
}
