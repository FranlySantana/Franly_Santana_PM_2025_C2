#include <stdio.h>

/*
Problema PS3.17
 Construye un diagrama de flujo y un programa en Cque,al recibir como dato un
 número entero positivo,escriba una figura como la que se muestra a continua
 ción (ejemplo para N = 7):
 1
 1  2  1
 1  2  3  2  1
 1  2  3  4  3  2  1
 1  2  3  4  5  4  3  2  1
 1  2  3  4  5  6  5  4  3  2  1
 1  2  3  4  5  6  7  6  5  4  3  2  1
 Dato:N(variable de tipo entero que representa el número que se ingresa).*/

#include <stdio.h>

#include <stdio.h>

void main(void) {
    int N;
    int i;
    int j;
    int k;

    printf("Generador de Patrones Numericos \n");
    printf("Ingresa un numero entero positivo (N): ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Error: Por favor, ingresa un numero entero positivo.\n");
        return;
    }

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        for (k = i - 1; k >= 1; k--) {
            printf("%d ", k);
        }

        printf("\n");
    }
}
