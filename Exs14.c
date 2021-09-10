//Exs14 
#include <stdio.h>

int main(){

    int item;
    int controle;
    
    printf("Escolha um item dentre as seguintes opcoes e digite o numero correspondente:");
    printf("\n1 - Remedios\n2 - Alimentacao\n3 - Perfumaria\n4 - Brinquedo\n5 - Produto sem desconto\n");
    
    for(controle=0; controle<1; controle++){
        scanf("%d", &item);
        
        switch(item){
            case 1:
                printf("\nRemedios - descontode de 30%%");
                break;
            case 2:
                printf("\nAlimentacao - desconto de 15%%");
                break;
            case 3:
                printf("\nPerfumaria - desconto de 10%%");
                break;
            case 4:
                printf("\nBrinquedos - desconto de 07%%");
                break;
            case 5:
                printf("\nProduto sem desconto.");
                break;
            default:
                printf("\nEscolha outra Opcao");
                controle-=1;
                break;
        }
    }

return 0;
}

