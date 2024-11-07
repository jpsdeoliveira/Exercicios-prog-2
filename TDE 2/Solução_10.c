/*Exercício 10: Escreva um programa que leia uma string e conte o número de letras, dígitos e caracteres especiais presentes nela. Use as funções isalpha() e isdigit() da biblioteca <ctype.h> para verificar o tipo de cada caractere.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

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
  printf("O número de caracteres especiais na string é: %d\n", countEspeciais);

  return 0;
}
