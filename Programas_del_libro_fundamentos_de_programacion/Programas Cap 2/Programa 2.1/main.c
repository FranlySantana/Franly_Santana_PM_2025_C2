#include <stdio.h>

/*El promedio curso.
El programa, al recibir como dato el promedio de un alumno en un curso
Universitario, escribe aprobado si su promedio es mayor o igual a 6.

PRO: Variable de tipo real.*/

void main(void)
{

    float PRO;
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &PRO);
    if (PRO >= 6){
        printf("\nAprobado");
    }

}
