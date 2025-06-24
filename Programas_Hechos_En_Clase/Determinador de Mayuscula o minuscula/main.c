#include <stdio.h>

int main() {
    char caracter;


    printf("Ingresa una letra: ");
    scanf(" %c", &caracter);


    if (caracter >= 'A' && caracter <= 'Z') {
        printf("'%c' es una letra MAYÚSCULA.\n", caracter);
    }

    else if (caracter >= 'a' && caracter <= 'z') {
        printf("'%c' es una letra MINÚSCULA.\n", caracter);
    }

    else {
        printf("'%c' no es una letra del alfabeto.\n", caracter);
    }

    return 0;
}
