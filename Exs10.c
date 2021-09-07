//Exs 10

#include<stdio.h>

int main(){

	int a, s, i;

	scanf("%d", &a);

	s = 100;
	i = 19;
	
	while (s < a) {

	s -= i;
	i -= 2;
	
	}
	
	printf("%d\n", s);

return 0;
}

//Digitando 44 (RA 254344) a saida sera 100