#include <stdio.h>


void main(void)
{
    int menu = 0;

    do{
        printf("\n0-Salir\n1-Sumar\n2-Multiplicar\n");
        scanf("%d", &menu);

        if(menu < 0 || menu > 2){
            printf("\nValor de menu invalido");
        }

    }while(menu != 0);



}
