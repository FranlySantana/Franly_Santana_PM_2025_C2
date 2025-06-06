#include <stdio.h>
#include <math.h>

/*
Problema PS3.14
 Construye un diagrama de flujo y el correspondiente programa en C que,al recibir
 como dato una Xcualquiera,calcule el sen(x)utilizando la siguiente serie:

 La diferencia entre la serie y un nuevo término debe ser menor o igual a 0.001.
 Imprima el número de términos requerido para obtener esta precisión.

 Dato:X(variable de tipo entero que representa el número que se ingresa). */

void main(void) {
    double x;
    double seno_calculado = 0.0;
    double termino_actual;
    int n = 0;
    int numero_terminos = 0;
    int signo = 1;

    printf("Calculo de sen(x) por serie de Taylor\n");
    printf("Ingrese el valor de X (en radianes): ");
    scanf("%lf", &x);

    do {
        double potencia_x = 1.0;
        long long factorial_denominador = 1;
        int i;
        int exponente = 2 * n + 1;

        for (i = 0; i < exponente; i++) {
            potencia_x *= x;
        }

        for (i = 1; i <= exponente; i++) {
            factorial_denominador *= i;
        }

        termino_actual = (double)signo * (potencia_x / factorial_denominador);

        if (n > 0 && fabs(termino_actual) <= 0.001) {
            break;
        }

        seno_calculado += termino_actual;
        numero_terminos++;

        n++;
        signo *= -1;

    } while (1);

    printf("\nResultado de sen(%.4f) = %.6f\n", x, seno_calculado);
    printf("Numero de terminos usados: %d\n", numero_terminos);
}


