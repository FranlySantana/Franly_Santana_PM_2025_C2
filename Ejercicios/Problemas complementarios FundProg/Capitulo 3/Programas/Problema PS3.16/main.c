#include <stdio.h>

/*
 Problema PS3.16
 Construye un diagrama de flujo y el correspondiente programa en Cque,al recibir
 como dato un número entero positivo,escriba una figura como la que se muestra
 a continuación (ejemplo para N = 6):
 1
 1  2
 1  2  3
 1  2  3  4
 1  2  3  4  5
 1  2  3  4  5  6
 1  2  3  4  5
 1  2  3  4
 1  2  3
 1  2
 1
 Dato:N(variable de tipo entero que representa el número que se ingresa)*/

void main(void) {
    int N;
    int i;
    int j;

    printf("Generador de Figura Numerica \n");
    printf("Ingrese un numero entero positivo (N): ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Error: Por favor, ingrese un numero entero positivo.\n");
        return;
    }

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    for (i = N - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}
