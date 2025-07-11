#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[50];
    float promedio;
} Alumno;

void guardarAlumnoEnDisco(Alumno *unAlumno, FILE *archivo)
{
    fwrite(unAlumno, sizeof(Alumno), 1, archivo);
}

Alumno *leerAlumnoDesdeDisco(FILE *archivo)
{
    Alumno *unAlumno = (Alumno *)malloc(sizeof(Alumno));

    if (unAlumno == NULL)
    {
        perror("Error al asignar memoria para leer alumno");
        return NULL;
    }

    if (fread(unAlumno, sizeof(Alumno), 1, archivo) == 1)
    {
        return unAlumno;
    }
    else
    {
        free(unAlumno);
        return NULL;
    }
}

int main()
{
    FILE *archivoAlumnos;
    Alumno *nuevoAlumno = NULL;
    Alumno *alumnoLeido = NULL;
    Alumno **listaAlumnos = NULL;
    int numAlumnos = 0;

    printf(" GRABAR DATOS DE ALUMNOS \n");
    archivoAlumnos = fopen("alumnos.dat", "wb");

    if (archivoAlumnos == NULL)
    {
        perror("Error al abrir el archivo para escritura");
        return 1;
    }

    char opcion;
    do
    {
        nuevoAlumno = (Alumno *)malloc(sizeof(Alumno));
        if (nuevoAlumno == NULL)
        {
            perror("Error al asignar memoria para nuevo alumno");
            break;
        }

        printf("\nDatos del Alumno %d:\n", numAlumnos + 1);
        printf("Matricula: ");
        scanf("%d", &nuevoAlumno->matricula);
        while (getchar() != '\n');

        printf("Nombre: ");
        fgets(nuevoAlumno->nombre, sizeof(nuevoAlumno->nombre), stdin);
        nuevoAlumno->nombre[strcspn(nuevoAlumno->nombre, "\n")] = 0;

        printf("Promedio: ");
        scanf("%f", &nuevoAlumno->promedio);
        while (getchar() != '\n');

        guardarAlumnoEnDisco(nuevoAlumno, archivoAlumnos);
        printf("Alumno guardado en disco.\n");

        free(nuevoAlumno);
        nuevoAlumno = NULL;

        printf("¿Deseas ingresar otro alumno? (s/n): ");
        scanf(" %c", &opcion);

    } while (opcion == 's' || opcion == 'S');

    fclose(archivoAlumnos);
    printf("\nDatos de alumnos guardados correctamente.\n");

    printf("\n LEYENDO DATOS DE ALUMNOS DESDE DISCO \n");
    archivoAlumnos = fopen("alumnos.dat", "rb");

    if (archivoAlumnos == NULL)
    {
        perror("Error al abrir el archivo para lectura");
        return 1;
    }

    while ((alumnoLeido = leerAlumnoDesdeDisco(archivoAlumnos)) != NULL)
    {
        Alumno **tempLista = (Alumno **)realloc(listaAlumnos, (numAlumnos + 1) * sizeof(Alumno *));

        if (tempLista == NULL)
        {
            perror("Error al reasignar memoria para lista de alumnos");
            free(alumnoLeido);
            break;
        }

        listaAlumnos = tempLista;
        listaAlumnos[numAlumnos] = alumnoLeido;
        numAlumnos++;
    }

    fclose(archivoAlumnos);

    printf("\n ALUMNOS CARGADOS EN MEMORIA DINAMICA (%d alumnos) \n", numAlumnos);
    if (numAlumnos == 0)
    {
        printf("No se encontraron alumnos en el archivo.\n");
    }
    else
    {
        Alumno **ptrActual = listaAlumnos;
        for (int i = 0; i < numAlumnos; i++)
        {
            printf("\nAlumno %d:\n", i + 1);
            printf("  Matricula: %d\n", (*ptrActual)->matricula);
            printf("  Nombre: %s\n", (*ptrActual)->nombre);
            printf("  Promedio: %.2f\n", (*ptrActual)->promedio);

            ptrActual++;
        }
    }

    printf("\n LIBERANDO MEMORIA DINAMICA \n");
    for (int i = 0; i < numAlumnos; i++)
    {
        free(listaAlumnos[i]);
        listaAlumnos[i] = NULL;
    }
    free(listaAlumnos);
    listaAlumnos = NULL;

    printf("Memoria liberada. Programa finalizado.\n");

    return 0;
}
