//Exs3
#include <stdio.h>
int main(){

float velocidade, v;

printf("Escreva uma velocidade em km/h:\n");
scanf("%f", &velocidade);

v = (velocidade/3.6);

printf("A velocidade em m/s eh: %.2f\n", v);

return 0;	
}