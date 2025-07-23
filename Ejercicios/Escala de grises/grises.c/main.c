#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s archivo.jpg\n", argv[0]);
        return 1;
    }

    const char *nombreArchivo = argv[1];
    int ancho, alto, canales;

    unsigned char *imagen = stbi_load(nombreArchivo, &ancho, &alto, &canales, 0);
    if (imagen == NULL) {
        printf("No se pudo cargar la imagen: %s\n", nombreArchivo);
        return 1;
    }

    int totalPixeles = ancho * alto;
    unsigned char *grises = malloc(totalPixeles * canales);
    if (grises == NULL) {
        printf("No se pudo asignar memoria.\n");
        stbi_image_free(imagen);
        return 1;
    }

    for (int i = 0; i < totalPixeles; i++) {
        int r = imagen[i * canales + 0];
        int g = imagen[i * canales + 1];
        int b = imagen[i * canales + 2];

        unsigned char gris = (r * 0.3) + (g * 0.59) + (b * 0.11);

        grises[i * canales + 0] = gris;
        grises[i * canales + 1] = gris;
        grises[i * canales + 2] = gris;

        if (canales == 4) {
            grises[i * canales + 3] = imagen[i * canales + 3];
        }
    }

    stbi_write_png("salida_gris.png", ancho, alto, canales, grises, ancho * canales);

    printf(" Imagen convertida: salida_gris.png\n");

    stbi_image_free(imagen);
    free(grises);

    return 0;
}

