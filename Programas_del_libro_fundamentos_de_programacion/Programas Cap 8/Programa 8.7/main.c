#include <stdio.h>
#include <string.h>

/* Escuela.
   El programa genera información importante de los alumnos de una escuela. */

typedef struct {
    char mat[20];   // Materia
    int pro;        // Promedio
} matpro;

typedef struct {
    int matri;           // Matrícula
    char nom[20];        // Nombre del alumno
    matpro cal[5];       // Arreglo de estructuras matpro
} alumno;

// Prototipos
void Lectura(alumno*, int);
void F1(alumno*, int);
void F2(alumno*, int);
void F3(alumno*, int);

void main(void) {
    alumno ALU[50];
    int TAM;

    do {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);  // Validación

    Lectura(ALU, TAM);
    F1(ALU, TAM);
    F2(ALU, TAM);
    F3(ALU, TAM);
}

void Lectura(alumno A[], int T) {
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\nIngrese los datos del alumno %d", I + 1);
        printf("\nIngrese la matrícula del alumno: ");
        scanf("%d", &A[I].matri);
        fflush(stdin);
        printf("Ingrese el nombre del alumno: ");
        gets(A[I].nom);

        for (J = 0; J < 5; J++) {
            printf("\tMateria %d: ", J + 1);
            fflush(stdin);
            gets(A[I].cal[J].mat);
            printf("\tPromedio %d: ", J + 1);
            scanf("%d", &A[I].cal[J].pro);
        }
    }
}

void F1(alumno A[], int T) {
    int I, J;
    float SUM;
    for (I = 0; I < T; I++) {
        printf("\nMatrícula del alumno: %d", A[I].matri);
        SUM = 0.0;
        for (J = 0; J < 5; J++)
            SUM += A[I].cal[J].pro;
        SUM = SUM / 5;
        printf("\tPromedio: %.2f", SUM);
    }
}

void F2(alumno A[], int T) {
    int I;
    printf("\n\nAlumnos con calificación mayor a 9 en la tercera materia:");
    for (I = 0; I < T; I++) {
        if (A[I].cal[2].pro > 9) {
            printf("\nMatrícula del alumno: %d", A[I].matri);
        }
    }
}

void F3(alumno A[], int T) {
    int I;
    float SUM = 0.0;
    for (I = 0; I < T; I++)
        SUM += A[I].cal[3].pro;
    SUM = SUM / T;
    printf("\n\nPromedio de la cuarta materia: %.2f", SUM);
}
