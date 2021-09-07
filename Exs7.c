//Exs7
#include <stdio.h>
int main ( ){

int a, b, resultado;

scanf ("%d %d", &a, &b);

if (((a && b) || a) && ((!a && b) || !b))
	printf ("Expressao verdadeira\n");
else
	printf ("Expressao falsa\n");

return 0;
}

//00 -> Falsa
//01 -> Falsa
//10 -> Verdadeira
//11 -> Falsa