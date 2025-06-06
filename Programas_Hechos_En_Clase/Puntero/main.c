#include <stdio.h>


/*Recordar: que es un puntero, a donde señala.*/
//Repasar algunas temas...
int main() {
    int a;
    int b;
    int *p;

    p = &a;
    *p = 5;
    printf("\nValor de a: %i", *p);
    printf("\nDireccion de a (via p): %p", p);

    p = &b;
    *p = 100;
    printf("\nValor de b: %i", *p);
    printf("\nDireccion de b (via p): %p", p);

    printf("\nDireccion de a: %p", &a);
    printf("\nDireccion de b: %p", &b);

    return 0;
}
