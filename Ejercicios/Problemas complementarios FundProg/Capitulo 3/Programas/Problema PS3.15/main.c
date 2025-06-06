#include <stdio.h>

void main(void) {
    int N1, N2;
    int temporal;

    printf(" Calculador del Maximo Comun Divisor (MCD) \n");
    printf("Ingrese el primer numero natural (N1): ");
    scanf("%d", &N1);
    printf("Ingrese el segundo numero natural (N2): ");
    scanf("%d", &N2);

    if (N1 < 0 || N2 < 0) {
        printf("Error: Por favor, ingrese solo numeros naturales (0 o positivos).\n");
        return;
    }

    if (N1 == 0 && N2 == 0) {
        printf("El MCD de 0 y 0 es indefinido en este contexto (a menudo se considera 0 o un error).\n");
        return;
    }

    if (N1 == 0) {
        printf("El MCD de 0 y %d es: %d\n", N2, N2);
        return;
    }

    if (N2 == 0) {
        printf("El MCD de %d y 0 es: %d\n", N1, N1);
        return;
    }

    while (N2 != 0) {
        temporal = N2;
        N2 = N1 % N2;
        N1 = temporal;
    }

    printf("El Maximo Comun Divisor (MCD) es: %d\n", N1);
}
