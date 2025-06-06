#include <stdio.h>
#include <math.h>

/*Problema PS3.13
 Construye un diagrama de flujo y el correspondiente programa en C que, al recibir
 como datos dos números enteros positivos, obtenga e imprima todos los números
 primos gemelos comprendidos entre dichos números. Los primos gemelos son
 una pareja de números primos con una diferencia entre sí de exactamente dos. El
 3 y el 5 son primos gemelos.

 Datos: N1, N2 (variables de tipo entero que representan los números enteros po
 sitivos que se ingresan)*/

 int i;
    int primo(int NUM){
    if (NUM<=1){
        return 0;
    }

        if(NUM==2){
            return 1;
        }

        if (NUM%2==0){
            return 0;
        }

   for(i=3; i*i<=NUM; i=i+2){
    if (NUM%i==0){
        return 0;
    }
   }
    return 1;
    }


void main(void)
{

    int N1, N2;
    int limiteS;
    int limiteI;
    int NUMA;

    printf("\nBuscador de primos gemelos\n");
    printf("Ingrese el primer numero entero positivo: ");
    scanf("%d",&N1);
    printf("Ingrese el segundo numero entero positivo: ");
    scanf("%d",&N2);

    if(N1<N2){
        limiteI=N1;
        limiteS=N2;
    }else{
    limiteI=N2;
    limiteS=N1;
    }
    printf("\nBuscando primos entre %d y %d: \n",N1,N2);


    for(NUMA=limiteI; NUMA<=limiteS-2;NUMA++){
       if(primo(NUMA)==1&&primo(NUMA+2)==1){
        printf("(%d, %d)\n",NUMA, NUMA+2);
       }
    }

    }

