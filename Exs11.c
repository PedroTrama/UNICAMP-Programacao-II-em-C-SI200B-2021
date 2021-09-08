//Exs11

#include<stdio.h>

int main(){

	int a, s, i;

	scanf("%d", &a);

	s = 100;
	i = 19;
	
	do{
	s -= i;
	i -= 2;

	printf("%d\n", s);

	} while (s < a);

return 0;
}