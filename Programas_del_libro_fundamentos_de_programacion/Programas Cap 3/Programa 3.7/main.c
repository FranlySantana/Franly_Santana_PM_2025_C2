#include <stdio.h>

/*Lanzamiento de martillo.
El programa, al recibir como dato N lanzamientos de martillo, calcula el promedio
de los lanzamientos de la atleta cubana.

I, N: Variables de tipo entero.
LAN, SLA: Variables de tipo real.*/

void main(void)
{

    int I, N;
    float LAN, SLA = 0;
    do{

        printf("Ingrese el numero de lanzamientos:\t");
        scanf("%d", &N);

    }while(N<1||N>11);
  /*Su utiliza la estructura de while para verificar que el valor de N sea correcto.*/
  for(I=1; I<=N; I++){

    printf("\nIngrese el lanzamiento %d: ", I);
    scanf("%f", &LAN);
    SLA = SLA + LAN;

  }
    SLA = SLA / N;
    printf("\nEl promedio de lanzamientos es: %.2f", SLA);
}
