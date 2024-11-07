/*Exercício 8: Implemente um programa que leia uma string e conte o número de vogais presentes nela. Considere as vogais 'a', 'e', 'i', 'o', 'u' (maiúsculas e minúsculas).*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

  char str[100];
  int count = 0;

  printf("Digite uma string: ");
  scanf("%s", str);

  for (int i = 0; str[i] != '\0'; i++){
      if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
          count++;
      }
  }

  printf("O número de vogais na string é: %d\n", count);

  return 0;
}
