#include <stdio.h>

/* Alumnos.
El programa lee bloques �variables de tipo estructura  alumno� de un archivo
de acceso directo. */
typedef struct { /* Declaraci�n de la estructura  alumno. */
  int matricula;
  char nombre[20];
  int carrera;
  float promedio;
} alumno;
void lee(FILE *); /* Prototipo de funci�n. */
void main(void) {
  FILE *ar;
  if ((ar = fopen("ad1.dat", "r")) != NULL)
    lee(ar);
  else
    printf("\nEl archivo no se puede abrir");
  fclose(ar);
}
void lee(FILE *ap)
/* Esta funci�n se utiliza para leer bloques de un archivo de acceso directo. */
{
  alumno alu;
  fread(&alu, sizeof(alumno), 1, ap);
  /* Observa que la funci�n fread tiene los mismos argumentos que la funci�n
  fwrite del programa anterior. Tambi�n es importante tomar nota de que cuando
  tenemos que leer los registros de un archivo utilizando una estructura
  repetitiva como el wwhhiillee, debemos realizar una primera lectura antes de
  ingresar al ciclo y luego las siguientes dentro del ciclo, pero como �ltima
  instrucci�n del mismo. Esto se debe a que la l�gica que siguen las
  instrucciones fwrite  y fread  es moversey leer o escribir, seg�n sea el caso.
  Si no lo hici�ramos de esta forma, terminar�amos escribiendo la informaci�n
  del �ltimo registro dos veces. Vamos a realizar un ejemplo sencillo para
  comprobar esto. */
  while (!feof(ap)) {
    printf("\nMatr�cula: %d", alu.matricula);
    printf("\tCarrera: %d", alu.carrera);
    printf("\tPromedio: %f\t ", alu.promedio);
    puts(alu.nombre);
    fread(&alu, sizeof(alumno), 1, ap);
  }
}
