#include <stdio.h>

int main(){

	char titulo[100];
	char texto[2000];

	FILE *arquivo;
	
		scanf("%s", titulo);
		while (getchar() != '\n');

	arquivo = fopen(titulo, "w");

		fgets(texto,2000,stdin);
		fprintf(arquivo, "%s", texto);

	fclose(arquivo);

return 0;	
}

