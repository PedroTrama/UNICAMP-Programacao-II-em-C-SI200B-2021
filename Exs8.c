//Exs 8

#include <stdio.h> 
#include<string.h>

int main(){

	char numero[100]; 
	int digito;
	int tamanho;

	printf("Escreva seu numero que nao termina em 0:"); 
	gets(numero); 

	tamanho = strlen(numero); 
	printf("Invertendo seu numero temos: "); 

	for(digito = tamanho-1; digito >= 0; digito--){
		printf("%c" ,numero[digito]);
	}

	getch();

return 0;
}
