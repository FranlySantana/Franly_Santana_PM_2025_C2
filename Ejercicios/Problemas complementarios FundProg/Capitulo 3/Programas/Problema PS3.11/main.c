#include <stdio.h>
/* Problema PS3.11
En una bodega en Tarija, Bolivia, manejan información sobre las cantidades pro
ducidas de cada tipo de vino en los últimos años. Escribe un diagrama de flujo y
 el correspondiente programa en C que permita calcular lo siguiente:

    a. El total producido de cada tipo de vino en los últimos años.
    b. El total de la producción anual de los últimos años.

    Datos:N, VIN1, VIN2, VIN3, VIN4

Donde: N es una variable de tipo entero que representa el número de años.
VIN# es una variable de tipo real que representa la cantidad de litros de
vino en el año i del tipo # (1≤ i ≤ N, 1≤ j ≤ 4).  */

void main(void)
{
    int N;
    int I;
    float VINA1, VINA2, VINA3, VINA4;
    float VIN1=0.0, VIN2=0.0, VIN3=0.0, VIN4=0.0;
    float TLA;
    float PTA;



    printf("Calculo de produccion de vino\n");
    printf("Ingrese el numero de anos a considerar: ");
    scanf("%d",&N);


    for(I=1; I<=N; I++){

        printf("\nAno %d \n", I);
        printf("Ingrese la cantidad de litros producidos para:\n");
        printf("Vino tipo 1: ");
        scanf("%f", &VINA1);
        printf("Vino tipo 2: ");
        scanf("%f", &VINA2);
        printf("Vino tipo 3: ");
        scanf("%f", &VINA3);
        printf("Vino tipo 4: ");
        scanf("%f", &VINA4);

        PTA = VINA1+VINA2+VINA3+VINA4;
        printf("Produccion total para el ano %d: %.2f litros\n",I,PTA);

        VIN1 += VINA1;
        VIN2 += VINA2;
        VIN3 += VINA3;
        VIN4 += VINA4;

        TLA = VIN1+VIN2+VIN3+VIN4;
    }
    printf("\nResumen de produncion totales por vino en los ultimos %d anos.\n",N);
    printf("Total producido de vino tipo 1: %.2f litros\n",VIN1);
    printf("Total producido de vino tipo 2: %.2f litros\n",VIN2);
    printf("Total producido de vino tipo 3: %.2f litros\n",VIN3);
    printf("Total producido de vino tipo 4: %.2f litros\n",VIN4);
    printf("Total general: %.2f litros",TLA);

}
