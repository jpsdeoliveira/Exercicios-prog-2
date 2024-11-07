/*Exercício 6: Implemente um programa que leia duas strings e as concatene em uma nova string. Use a função strcat() para realizar a concatenação e exiba o resultado.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

  char str1[100], str2[100], str3[200];

  printf("Digite a primeira string: ");
  scanf("%s", str1);
  printf("Digite a segunda string: ");
  scanf("%s", str2);

  strcpy(str3, str1);
  strcat(str3, str2);

  printf("String concatenada: %s\n", str3);

  return 0;
}
