#include <stdio.h>

int main(){
	
	char caractere;
	int contador = 1;

	FILE *arquivo;
	arquivo = fopen("arquivo_linhas.txt", "r");
	
    	while(!feof(arquivo)){
    		caractere = getc(arquivo);

    		if((caractere=='\n')){
    			
    			contador++;
    		}	
    	}

    	printf("Numero de linhas: %d\n", contador);

	fclose(arquivo);

return 0;	
}

