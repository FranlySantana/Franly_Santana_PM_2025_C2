#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nombre[50];
    float promedio;
} Alumno;

void quitarSaltoLinea(char *cadena) {
    size_t len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n') {
        cadena[len - 1] = '\0';
    }
}

void guardarAlumnos(const char *nombreArchivo, int cantidad) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    Alumno alumno;
    for (int i = 0; i < cantidad; i++) {
        printf("\nAlumno %d:\n", i + 1);

        while (getchar() != '\n');
        printf("Nombre: ");
        fgets(alumno.nombre, sizeof(alumno.nombre), stdin);
        quitarSaltoLinea(alumno.nombre);

        printf("Promedio: ");
        scanf("%f", &alumno.promedio);

        fwrite(&alumno, sizeof(Alumno), 1, archivo);
    }

    fclose(archivo);
}

int cargarAlumnos(const char *nombreArchivo, Alumno lista[]) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }

    int contador = 0;
    while (fread(&lista[contador], sizeof(Alumno), 1, archivo) == 1) {
        contador++;
    }

    fclose(archivo);
    return contador;
}

void ordenarPorNombre(Alumno lista[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (strcmp(lista[j].nombre, lista[j + 1].nombre) > 0) {
                Alumno temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

void ordenarPorPromedio(Alumno lista[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (lista[j].promedio > lista[j + 1].promedio) {
                Alumno temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

void mostrarAlumnos(Alumno lista[], int cantidad) {
    printf("\nLista de alumnos:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%s - Promedio: %.2f\n", lista[i].nombre, lista[i].promedio);
    }
}

int main() {
    int opcion, cantidad;
    Alumno lista[MAX];
    const char *archivo = "alumnos.dat";

    do {
        printf("\n----- MENU -----\n");
        printf("1. Guardar alumnos\n");
        printf("2. Mostrar alumnos ordenados por nombre\n");
        printf("3. Mostrar alumnos ordenados por promedio\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("¿Cuantos alumnos desea ingresar? ");
                scanf("%d", &cantidad);
                guardarAlumnos(archivo, cantidad);
                break;

            case 2:
                cantidad = cargarAlumnos(archivo, lista);
                ordenarPorNombre(lista, cantidad);
                mostrarAlumnos(lista, cantidad);
                break;

            case 3:
                cantidad = cargarAlumnos(archivo, lista);
                ordenarPorPromedio(lista, cantidad);
                mostrarAlumnos(lista, cantidad);
                break;

            case 0:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 0);

    return 0;
}
