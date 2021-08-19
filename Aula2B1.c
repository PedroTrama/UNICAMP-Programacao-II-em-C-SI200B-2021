//Elaborar um programa para ler e escrever: Um inteiro, um número real, um caracter, uma string
#include <stdio.h>
#include <string.h>
#define N 100 //usaremos esse N para limitar o tamanho da string

int main(){
	
	/*declaração das 4 variáveis que serão usadas: integer, float
	character e string*/
	int a;
	float b;
	char c;
	char d[N];

	//recebendo e printando o número do usuário
	printf("Escreva um numero natural: ");
	scanf("%d", &a);
	printf("Seu numero natural eh: %d\n", a);

	//recebendo e printando o número do usuário
	printf("Escreva um numero real com duas casas decimais: ");
	scanf("%f", &b); 
	printf("Seu numero real eh: %.2f\n", b);

	//recebendo e printando o caractere do usuário
	printf("Escreva um caractere simples: ");
	scanf("\n%c", &c);
	printf("Seu caractere eh: %c\n", c);

	//recebendo e printando a palavra do usuário
	printf("Escreva uma palavra sem espacos: ");
	scanf("\n%s", &d);
	printf("Sua palavra eh: %s\n", d);

//encerrando a execução do programa
return 0;
}