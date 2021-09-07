//Exs5
#include <stdio.h>
int main(){

float celsius, fahrenheit, c, f;

printf("Escreva uma temperatura em Celsius:\n");
scanf("%f", &celsius);

printf("Escreva uma temperatura em Fahrenheit:\n");
scanf("%f", &fahrenheit);

f = ((celsius*1.8) + 32);
c = ((farenheit-32)/1.8);

printf("%.2f graus Celsius sao %.2f graus Fahrenheit\n", celsius, f);
printf("%.2f graus Fahrenheit sao %.2f graus Celsius\n", fahrenheit, c);
return 0;	
}