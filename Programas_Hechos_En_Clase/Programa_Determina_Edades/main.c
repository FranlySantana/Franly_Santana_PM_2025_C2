#include <stdio.h>
#include <stdlib.h>

/*Escribir un programa que determine el rango de edad
de una persona:
1- de 0 años(anios) 1 año - recien nacido.
2- de 1 a 12 años.
3- de 12 años a 17 es adolecente.
4- de 18 a 38 es adulto.
5- de 39 a 75 adulto mayor.
6- de 76 a 86 es envejeciente.
7- mayor de 86 es anciano.*/

int main()
{
    //Declara la variable y se inicializa
    int edad = 0;
    printf("\nEscriba la edad del paciente: ");
    scanf("%i", &edad);

    //Validar datos     Criterios de evaluacion.
    if(edad >= 0  && edad < 130){

        if(edad <= 1){
            printf("Es un infante, dosis recomendada 0ML ");
        } else if(edad > 1 && edad <= 12){
        printf("Es un niño, dosis recomendada 0.5ML");
        } else if(edad >= 12 && edad <= 18){
        printf("Es un adolecente, dosis recomendada 0.75ML");
        } else if(edad >= 18 && edad <= 39){
        printf("Es un adulto, dosis recomendada 1.0ML");
        } else if(edad >= 39 && edad <= 75){
        printf("Es un adulto mayor, dosis recomendada 1.5ML");
        } else if(edad >= 75 && edad <= 86){
        printf("Es un envejeciente, dosis recomendada 1.7ML");
        } else if(edad >= 86 ){
        printf("Es un anciano, dosis recomendada 2ML");
        }

        //printf("\nEjecucion bloque if");

    } else{
    printf("\nValores no validos");
    }
    printf("\nFin del programa");
    return 0;
}
