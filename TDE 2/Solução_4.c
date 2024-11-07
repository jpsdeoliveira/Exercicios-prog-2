/*Exercício 4: Implemente um programa que leia uma string e verifique quantas vezes o caractere 'a' aparece nela. Exiba o total de ocorrências.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

  char str[100];
  int count = 0;

  printf("Digite uma string: ");
  scanf("%s", str);

  for (int i = 0; str[i] != '\0'; i++){
      if (str[i] == 'a'){
          count++;
      }
  }

  return 0;
}
