#include <stdio.h>
/*Nomina.
El programa, al recibir los salarios de 5 profesores, obtiene el total de la
nomina de la universidad

I: Variable de tipo entero.
Sal y NOM: Variables tipo real.*/

void main(void)
{
    int I;
    float Sal = 0.0, Nom = 0.0;
    float ITB = 0.20;

    float PagoSinITB = 0.0;
    float PagoConITB = 0.0;
    Nom = 0;

    for(I = 1; I <= 5; I++){
        printf("\nIngrese el salario del maestro %d:\t", I);
        scanf("%f", &Sal);
        PagoConITB = Sal * ITB;
        PagoSinITB = Sal - PagoConITB;
        printf("Pago a profesor: %.2f\n", PagoSinITB);
        Nom = Nom + Sal;

    }
    printf("----------------------------------");
    printf("\nImpuestos: %f",Nom * ITB);
    printf("\nEl pago de los profesores: %.2f", Nom - (Nom * ITB));
    printf("\nEl total de la nomina es: %.2f", Nom);

   // return 0;
}
