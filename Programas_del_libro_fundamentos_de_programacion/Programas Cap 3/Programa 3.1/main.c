#include <stdio.h>

/*Nomina.
El programa, al recibir los salarios de 15 profesores, obtiene el total de la
nomina de la universidad.

I: Variable de tipo entero.
SAL y NOM: Variables de tipo real.*/

void main(void)
{

    int I;
    float SAL, NOM;

    for(I=1; I<=15; I++){

        printf("\Ingrese el salario del profesor %d:\t", I);
        scanf("%f", &SAL);
        NOM = NOM + SAL;

    }
    printf("\nEl total de la nomina es: %.2f", NOM);
}
