/*Exercício 5: Crie um programa que leia uma string e a copie para outra variável usando a função strcpy(). Exiba as duas strings para verificar se a cópia foi bem-sucedida.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

  char str1[100], str2[100];

  printf("Digite uma string: ");
  scanf("%s", str1);
    
  strcpy(str2, str1);

  printf("String original: %s\n", str1);
  printf("String copiada: %s\n", str2);

  return 0;
}
