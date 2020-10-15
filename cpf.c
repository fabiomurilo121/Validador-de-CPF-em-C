//
// Created by Fabio-PC on 22/08/2020.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 14
#define TAMINT 11

char cpf[TAM];
int cpfInt[TAMINT],soma1[9],soma2[10];
int  k, x, h, u, l, somaDig1, somaDig2, resto1, resto2, primeiro, segundo;


char* remove_espacos(char* str) {
    char* nova_string = (char*)malloc(strlen(str)*sizeof(char));

    int i, j = 0;
	
    for (i = 0; i < strlen(str); i++)
        if (str[i] != ' ') nova_string[j++] = str[i];

    nova_string[j] = '\0';

    return nova_string;
}

void removeDivicao(char entrada[]){
    int i;
    for(i=0; i < strlen(entrada); ++i){
        if(entrada[i]=='.' || entrada[i]=='-'){
            entrada[i] = ' ';
        }
    }
}

void castInt(char string[], int inteiros[]){
    int j,aux[1];
    for (j = 0; j < strlen(string); ++j) {
        aux[0] = string[j];
        inteiros[j] = (int) atoi(aux);
    }
}

int main(){

    printf("informe seu CPF: xxx.xxx.xxx-xx\n",cpf);
    scanf("%s",&cpf);
    printf("CPF de entrada foi: %s\n",cpf);
    removeDivicao(cpf);
    castInt(remove_espacos(cpf),cpfInt);

    for (k = 10, h = 0; h < 9; --k, ++h) {
        soma1[h] = (cpfInt[h] * k);
    }

	
    for (l = 0; l < 9; ++l) {
        somaDig1 += soma1[l];
    }

    if (somaDig1 % 11 == 0 || somaDig1 % 11 == 1) {
        cpfInt[9] = 0;
    } else{
        resto1 = somaDig1 % 11;
        primeiro = 11 - resto1;
    }

    for (u = 11, x = 0; x < 10; --u, ++x) {
        soma2[x] = (cpfInt[x] * u);
    }


    for (l = 0; l < 10; ++l) {
        somaDig2 += soma2[l];
    }


    if (somaDig2 % 11 == 0 || somaDig2 % 11 == 1) {
        cpfInt[10] = 0;
    } else{
        resto2 = somaDig2 % 11;
        segundo = 11 - resto2;
    }


    if (primeiro == cpfInt[9] && segundo == cpfInt[10]){
        printf("CPF Valido !!!\n");
        printf("Digito Verificador eh: %d%d\n",primeiro,segundo);
    } else{
        printf("CPF Nao aceito !!!\n");
        printf("Digito Verificador eh: %d%d\n",primeiro,segundo);
    }

    system("PAUSE");
}
