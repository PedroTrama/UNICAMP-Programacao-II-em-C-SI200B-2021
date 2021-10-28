#include <stdio.h>

int main(){
	
	char c;
	int contador = 0;

	FILE *arquivo;
	arquivo = fopen("arquivo_base.txt", "r");
	
    	while(!feof(arquivo)){
    		c = getc(arquivo);

    		if((c==' ') || (c=='\n')){
    		}

    		else{
    			contador++;
    		}
    	}

    	printf("Numero de caracteres: %d\n", contador);

	fclose(arquivo);

	arquivo = fopen("arquivo_base.txt", "a");

		fprintf(arquivo, "\nNumero de caracteres: %d", contador);

	fclose(arquivo);

return 0;	
}