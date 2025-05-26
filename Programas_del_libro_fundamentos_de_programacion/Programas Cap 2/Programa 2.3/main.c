#include <stdio.h>

/* Promedio curso.
El programa, al recibir como dato el promedio de un alumno en un curso
Universitario, escribe aprobado si su promedio es mayor o igual a 6, o
reprobado en caso contrario*/

void main(void)
{

    float PRO;
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &PRO);
    if (PRO >= 6)

        printf("\nAprobado");


    else
    printf("\nReprobado");


}
