/*Faça um programa em C para ler uma temperatura em graus Celsius
e transformá-la em Farenheit. Utilize a seguinte fórmula:
F = ((9 * C) / 5) + 32*/
#include <stdio.h>
int main(){

	float c;//variavel da temperatura em graus C

	//recebendo o valor em graus C
	printf("Digite uma temperatura em graus Celsius: ");
	scanf("%f", &c);

	//calculando e printando o valor na tela
	printf("A temperatura em Farenheit eh: %.2f\n", ((9*c)/5) + 32);

return 0;	
}