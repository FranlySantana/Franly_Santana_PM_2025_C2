#include <stdio.h>

/*
 Problema PS3.18
 Construye un diagrama de flujo y un programa en Cque,al recibir como dato un
 número entero positivo,escriba una figura como la que se muestra a continua
 ción (ejemplo para N = 7):
 1  2  3  4  5  6  7      7  6  5  4  3  2  1
 1  2  3  4  5  6              6  5  4  3  2  1
 1  2  3  4  5                      5  4  3  2  1
 1  2  3  4                              4  3  2  1
 1  2  3                                      3  2  1
 1  2                                              2  1
 1                                                      1
 Dato:N(variable de tipo entero que representa el número que se ingresa)*/

void main(void)
{
 int N;
    int i;
    int j;
    int espacios;
    int k;

    printf("Generador de Figura Numerica\n");
    printf("Ingrese un numero entero positivo (N): ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Error: Por favor, ingrese un numero entero positivo.\n");

    }

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= (N - i + 1); j++) {
            printf("%d ", j);
        }

        for (espacios = 1; espacios <= (i - 1) * 4; espacios++) {
            printf(" ");
        }

        for (k = (N - i + 1); k >= 1; k--) {
            printf("%d ", k);
        }

        printf("\n");
    }
}
