//Exs6
#include <stdio.h>
int main(){

float a, b, c, d, e, media;

printf("Escreva cinco numeros reais:\n");
scanf("%f", &a);
scanf("%f", &b);
scanf("%f", &c);
scanf("%f", &d);
scanf("%f", &e);

media = ((a+b+c+d+e)/5);

printf("A media dos numeros reais eh: %.2f\n", media);

return 0;	
}