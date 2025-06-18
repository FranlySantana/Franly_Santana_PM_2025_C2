#include <stdio.h>
/* Primos.
 El programa almacena en un arreglo unidimensional los primeros 100 números
 primos. */

const int TAM = 100;

void Imprime(int [], int);
void Primo(int, int *);

int main()
{
    int P[TAM];
    int FLA, J = 0, PRI = 1;


    if (TAM > 0) {
        P[J++] = 1;
    }
    if (TAM > 1) {
        P[J++] = 2;
    }
    PRI = 3;

    while (J < TAM)
    {
        FLA = 1;
        Primo(PRI, &FLA);
        if (FLA)
        {
            P[J] = PRI;
            J++;
        }
        PRI += 2;
    }
    Imprime(P, TAM);
    return 0;
}

void Primo(int A, int *B)
{
    int DI = 3;
    while (*B && (DI * DI <= A))
    {
        if ((A % DI) == 0)
        {
            *B = 0;
        }
        DI += 2;
    }
}

void Imprime(int Primos[], int T)
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("\nPrimos[%d]: %d", I, Primos[I]);
    }
}
