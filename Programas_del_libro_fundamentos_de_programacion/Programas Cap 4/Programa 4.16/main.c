
#include <stdio.h>
#include <math.h>

/* Temperaturas.
El programa recibe como datos 24 números reales que representan las
temperaturas en el exterior en un período de 24 horas. Calcula el
promedio del día y las temperaturas máxima y mínima con la hora en la
que se registraron. */

void Acutem(float);
void Maxima(float, int);
void Minima(float, int);

float ACT = 0.0;
float MAX = -50.0;
float MIN = 60.0;
int HMAX;
int HMIN;

void main(void)
{
    float TEM;
    int I;
    for (I = 1; I <= 24; I++)
    {
        printf("Ingresa la temperatura de la hora %d: ", I);
        scanf("%f", &TEM);
        Acutem(TEM);
        Maxima(TEM, I);
        Minima(TEM, I);
    }
    printf("\nPromedio del dia: %.2f", ACT / 24);
    printf("\nTemperatura maxima: %.2f (Hora: %d)", MAX, HMAX);
    printf("\nTemperatura minima: %.2f (Hora: %d)", MIN, HMIN);
}

void Acutem(float TEMP)
{
    ACT += TEMP;
}

void Maxima(float TEMP, int HORA)
{
    if (TEMP > MAX)
    {
        MAX = TEMP;
        HMAX = HORA;
    }
}

void Minima(float TEMP, int HORA)
{
    if (TEMP < MIN)
    {
        MIN = TEMP;
        HMIN = HORA;
    }
}
