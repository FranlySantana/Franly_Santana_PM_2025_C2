#include <stdio.h>

/* Incremento de precio.
El programa, al recibir como dato el precio de un producto importado,
PRE y NPR: Variable de tipo real.*/

void main(void)
{

    float PRE, NPR;
    printf("Ingrese el precio del producto: ");
    scanf("%f", &PRE);
    if (PRE > 1500){

        NPR = PRE * 1.11;
        printf("\nNuevo precio:  %7.2f", NPR);
    }

}
