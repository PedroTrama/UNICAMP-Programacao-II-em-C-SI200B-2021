//Exs13

#include <stdio.h>

int main(){

    char *romano[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int algarismos[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};   
    int controle;
    int posicao = (sizeof(algarismos) / sizeof(algarismos[0])) - 1;

    scanf("%d",&controle);

    while (controle > 0){
        if (controle >= algarismos[posicao]){
           
             printf("%s", romano[posicao]);
          
            controle -= algarismos[posicao];
        } 
            else{
                posicao--;
            }
    }
        printf("\n");

return 0;
}


