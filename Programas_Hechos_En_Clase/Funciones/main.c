#include <stdio.h>
/*Cubo.1.
El programa calcula el cubo de los 10 primeros numeros naturales con la
ayuda de una funcion. En la solucion del problema se utiliza una variable
global, aunque estp, como veremos mas adelante, no es muy recomendable. */
int cubo(void);
int I;

 void main(void)
{
    int CUB;
    for (I=1; I<=10; I++){
        CUB=cubo();
        printf("\nEl cubo de %i es: %i\n",CUB);
    }

}
int cubo(void){
return(I*I*I);
}
