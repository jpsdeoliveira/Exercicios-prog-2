/*Exercício 2: Implemente um programa que leia duas strings do usuário e verifique se elas são iguais. Exiba uma mensagem informando se as strings são iguais ou diferentes. Use a função strcmp() para a comparação.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char str1[100], str2[100];

    printf("Digite a primeira string: ");
    scanf("%s", str1);
    printf("Digite a segunda string: ");
    scanf("%s", str2);

    if (strcmp(str1, str2) == 0){
        printf("As strings são iguais.\n");
    }else{
        printf("As strings são diferentes.\n");
    }

    return 0;
}
