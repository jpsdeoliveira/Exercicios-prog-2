/*Exercício 9: Crie um programa que leia uma string e conte o número de espaços em branco nela. Exiba o total de espaços.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

  char str[100];
  int count = 0;

  printf("Digite uma string: ");
  scanf("%s", str);

  for (int i = 0; str[i] != '\0'; i++){
      if (str[i] == ' '){
          count++;
      }
  }

  printf("O número de espaços em branco na string é: %d\n", count);

  return 0;
}
