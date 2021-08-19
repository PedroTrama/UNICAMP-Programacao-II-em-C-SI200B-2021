//Elaborar um programa para ler um caracter e escrever seu valor numérico (ASCII)correspondente
#include <stdio.h>
int main(){
	//declaração das duas variáveis
	int ascii; //numero inteiro para a tabela ascii
	char caractere; //caractere a ser transformado
	char c; //variavel de controle

	//leitura do caractere desejado
	printf("Escreva um caractere simples: ");
	scanf("%c", &caractere);

	//conversão em ascii
	c = caractere;
	ascii = c;

	//printando o resultado
	printf("Seu caractere em ASCII eh: %d\n", ascii);

return 0;
}