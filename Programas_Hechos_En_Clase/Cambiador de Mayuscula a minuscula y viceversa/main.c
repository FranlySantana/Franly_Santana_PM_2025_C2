#include <stdio.h>
#include <ctype.h>

int esMayuscula(char c) {
    if (isupper(c)) {
        return 1;
    } else {
        return 0;
    }
}

int esMinuscula(char c) {
    if (islower(c)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char letra;

    printf("Ingresa una letra: ");
    scanf(" %c", &letra);

    if (esMayuscula(letra)) {
        printf("La letra '%c' en minúscula es: %c\n", letra, tolower(letra));
    } else if (esMinuscula(letra)) {
        printf("La letra '%c' en mayúscula es: %c\n", letra, toupper(letra));
    } else {
        printf("'%c' no es una letra del alfabeto. No se puede cambiar su caso.\n", letra);
    }

    return 0;
}
