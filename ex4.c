#include <stdio.h>

int main(){

	char titulo[100];
	char texto[2000];

	FILE *arquivo;
	
		scanf("%s", titulo);
		getchar();

	arquivo = fopen(titulo, "r");

		fscanf(arquivo, "%s", texto);

		printf("%s\n", texto);

	fclose(arquivo);

return 0;	
}


