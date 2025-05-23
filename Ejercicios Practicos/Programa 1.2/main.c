//Programa 1.2
#include <stdio.h>

/*Invierte datos.
El orden, al recibir como dato un conjunto de datos de entrada, invierte el
orden de los mismos cuando los imprime.

A, B, C, y D: variables de tipo entero. */

int main(void)
{
    int A, B, C, D;
    printf("Ingrese cuatro datos de tipo entero: ");
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("\n%d %d %d %d", D, C, B, A);


}
