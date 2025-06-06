#include <stdio.h>

/*
 Problema PS3.19
 Construye un diagrama de flujo y el correspondiente programa en Cque genere
 una figura como la que se muestra a continuación:

        1
       232
      34543
     4567654*/

void main(void) {
    int N;
    int i;
    int j;
    int k;
    int l;
    int num_a_imprimir;

    printf("Generador de Patrones Numericos\n");
    printf("Ingrese el numero de filas (N): ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Error: Por favor, ingrese un numero entero positivo.\n");
        return;
    }

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= (N - i); j++) {
            printf("  ");
        }

        num_a_imprimir = i;
        for (k = 1; k <= i; k++) {
            printf("%d ", num_a_imprimir % 10);
            num_a_imprimir++;
        }

        num_a_imprimir -= 2;
        for (l = 1; l <= i - 1; l++) {
            printf("%d ", num_a_imprimir % 10);
            num_a_imprimir--;
        }

        printf("\n");
    } }
