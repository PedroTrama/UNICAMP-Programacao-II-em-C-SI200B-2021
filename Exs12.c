//Exs 12
#include <stdio.h>

int main (void){
    int a, b;

    scanf("%d %d", &a, &b);
    int i, j, contador = 0;
    for (i = a; i < b; i++) {
        contador += i;
            for (j = i+1; j < b; j++) {
                contador++;
            }
    }

    printf("%d\n", contador);
    
    return 0;
}
/*
a) 2
b) 15
c) 28
d) 60
