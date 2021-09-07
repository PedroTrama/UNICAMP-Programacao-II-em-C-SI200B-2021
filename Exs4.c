//Exs4
#include <stdio.h>
int main(){

float raio, area;

printf("Escreva o raio de uma circunferencia:\n");
scanf("%f", &raio);

area = ((3.14)*raio*raio);

printf("A area da circunferencia eh: %.2f\n", area);

return 0;	
}