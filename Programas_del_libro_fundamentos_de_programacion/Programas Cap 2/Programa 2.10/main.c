#include <stdio.h>
#include <math.h>

/* Par, impar o nulo.
NUM: Variable de tipo entero.*/

void main(void)
{

   int NUM;
   printf("Ingrese el numero: ");
   scanf("%d", &NUM);
   if (NUM==0)
            printf("\nNulo");
   else
            if (pow (-1, NUM)>0)
                printf("\nPAR");
            else
                printf("\nInpar");

}
