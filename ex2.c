#include <stdio.h>

int main(){
	
	char c;
	int contador = 0;

	FILE *arquivo;
	arquivo = fopen("arquivo_base.txt", "r");
	
    	while(!feof(arquivo)){
    		c = getc(arquivo);

    		if((c=='a') || (c=='e')|| (c=='i')|| (c=='o')|| (c=='u')||(c=='A') || (c=='E')|| (c=='I')|| (c=='O')|| (c=='U')){
    		
    			contador++;	
    		}	
   		 }

    	printf("Numero de vogais: %d\n", contador);

	fclose(arquivo);

return 0;	
}


