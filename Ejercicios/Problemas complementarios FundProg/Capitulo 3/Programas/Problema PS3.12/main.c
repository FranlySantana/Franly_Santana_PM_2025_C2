#include <stdio.h>
#include<math.h>
/* Problema PS3.12
 Se dice que un número N es primo si los únicos enteros positivos que lo dividen
son exactamente 1 y N. Construye un diagrama de flujo y el correspondiente pro
grama en C que lea un número entero positivo NUM y escriba todos los números
primos menores a dicho número.

 Dato: NUM (variable de tipo entero que representa al número entero positivo que
 se ingresa). */

void main(void)
{
    int NUM;
    int NUMC;
    int divisor;
    int primo;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &NUM);
    printf("\nNumeros primos menores a %d\n",NUM);

    if (NUM <= 2) {
        printf("No hay numeros primos menores a %d\n", NUM);
    } else {
        printf("Los numeros primos menores a %d son: ", NUM);

        for (NUMC = 2; NUMC < NUM; NUMC++) {
            primo = 1;

        if (NUMC <= 1) {
                primo = 0;
        } else if (NUMC == 2) {
                primo = 1;
        } else if (NUMC % 2 == 0) {
                primo = 0;
        } else {
        for (divisor = 3; divisor <= sqrt(NUMC); divisor += 2) {
        if (NUMC % divisor == 0) {
            primo = 0;
            break;
    }
 }
}

    if (primo == 1) {
    printf("%d ", NUMC);
    }
  }
        printf("\n");
 }
}




