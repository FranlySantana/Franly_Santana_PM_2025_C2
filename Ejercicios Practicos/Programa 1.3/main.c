//Programa 1.3
#include <stdio.h>

/*Promedio de sueldos.
El programa, al recibir como datos seis sueldos de un empleado, calcula
tanto el ingreso total como el promedio mensual.

CLA: Variable de tipo entero.
su1, su2, su3, su4, su5, su6, ING, PRO; Variables de tipo real.*/
int main(void)
{
    int CLA;
    float su1, su2, su3, su4, su5, su6, ING, PRO;
    printf("Ingrese la clave del empleado y los 6 sueldos: \n");
    scanf("%d %f %f %f %f %f %f", &CLA, &su1, &su2, &su3, &su4, &su5, &su6);
    ING = (su1 + su2 + su3 + su4 + su5 + su6);
    PRO = ING / 6;
    printf("\n %d %5.2f %5.2f", CLA, ING, PRO);

}
