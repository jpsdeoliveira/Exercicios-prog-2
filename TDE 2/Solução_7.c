/*Exercício 7: Escreva um programa que leia uma string e substitua todos os caracteres minúsculos por maiúsculos. Utilize a função toupper() da biblioteca <ctype.h> para auxiliar na conversão.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

  char str[100];

  printf("Digite uma string: ");
  scanf("%s", str);

  for (int i = 0; str[i] != '\0'; i++){
      str[i] = toupper(str[i]);
  }

  printf("String em maiúsculas: %s\n", str);

  return 0;
}
