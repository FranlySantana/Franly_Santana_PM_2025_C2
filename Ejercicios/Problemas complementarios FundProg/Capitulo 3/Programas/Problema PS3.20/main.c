#include <stdio.h>

 /*
 Problema PS3.20
 Construye un diagrama de flujo y el correspondiente programa en C que escriba
 todos los valores positivos de T, Py Rque satisfagan la siguiente expresión.
 7*T4 - 6*P3 + 12*R5 < 5850
 Nota:T, Py Rsólo pueden tomar valores positivos.*/

void main(void)
{
     long long T, P, R;
    long long terminoT4;
    long long terminoP3;
    long long terminoR5;
    long long resultado_expresion;
    int contador_soluciones = 0;

    printf("Buscador de soluciones para 7*T^4 - 6*P^3 + 12*R^5 < 5850\n");
    printf("T, P, R deben ser enteros positivos.\n\n");
    printf("Soluciones encontradas (T, P, R):\n");

    for (T = 1; T <= 5; T++) {
        for (P = 1; P <= 9; P++) {
            for (R = 1; R <= 3; R++) {
                terminoT4 = T * T * T * T;
                terminoP3 = P * P * P;
                terminoR5 = R * R * R * R * R;

                resultado_expresion = (7 * terminoT4) - (6 * terminoP3) + (12 * terminoR5);

                if (resultado_expresion < 5850) {
                    printf("(%lld, %lld, %lld)\n", T, P, R);
                    contador_soluciones++;
                }
            }
        }
    }

    printf("\nSe encontraron %d combinaciones que satisfacen la expresion.\n", contador_soluciones);
}
