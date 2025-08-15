#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char placa[10];
    char marca[20];
    char modelo[20];
    char tipo_combustible[10];
    float km_por_galon_carretera;
    float km_por_galon_ciudad;
    float costo_gomas;
    int km_gomas;
    float costo_seguro_anual;
    float costo_mantenimiento;
    int km_mantenimiento;
    float costo_vehiculo;
    int vida_util_anos;
    float depreciacion_anual;
    int km_anuales_promedio;
} Vehiculo;

typedef struct {
    float costo_gasolina;
    float costo_gasoil;
} DatosGenerales;

#define ARCHIVO_VEHICULOS "vehiculos.txt"
#define ARCHIVO_DATOS_GENERALES "datos_generales.txt"
#define MAX_VEHICULOS 100

void crear_vehiculo();
void borrar_vehiculo();
void modificar_vehiculo();
void listar_vehiculos();
void actualizar_costos_combustible();
void calcular_costo_viaje();

void guardar_vehiculo(const Vehiculo *v);
void guardar_vehiculos_en_archivo(const Vehiculo vehiculos[], int num_vehiculos);
int cargar_vehiculos(Vehiculo vehiculos[]);
void guardar_datos_generales(const DatosGenerales *dg);
void cargar_datos_generales(DatosGenerales *dg);
int buscar_vehiculo_por_placa(const Vehiculo vehiculos[], int num_vehiculos, const char *placa);

int cargar_vehiculos(Vehiculo vehiculos[]) {
    FILE *archivo = fopen(ARCHIVO_VEHICULOS, "r");
    if (archivo == NULL) {
        return 0;
    }
    int num_vehiculos = 0;
    while (fscanf(archivo, "%s %s %s %s %f %f %f %d %f %f %d %f %d %f %d\n",
                  vehiculos[num_vehiculos].placa,
                  vehiculos[num_vehiculos].marca,
                  vehiculos[num_vehiculos].modelo,
                  vehiculos[num_vehiculos].tipo_combustible,
                  &vehiculos[num_vehiculos].km_por_galon_carretera,
                  &vehiculos[num_vehiculos].km_por_galon_ciudad,
                  &vehiculos[num_vehiculos].costo_gomas,
                  &vehiculos[num_vehiculos].km_gomas,
                  &vehiculos[num_vehiculos].costo_seguro_anual,
                  &vehiculos[num_vehiculos].costo_mantenimiento,
                  &vehiculos[num_vehiculos].km_mantenimiento,
                  &vehiculos[num_vehiculos].costo_vehiculo,
                  &vehiculos[num_vehiculos].vida_util_anos,
                  &vehiculos[num_vehiculos].depreciacion_anual,
                  &vehiculos[num_vehiculos].km_anuales_promedio) == 15) {
        num_vehiculos++;
        if (num_vehiculos >= MAX_VEHICULOS) break;
    }
    fclose(archivo);
    return num_vehiculos;
}

void guardar_vehiculos_en_archivo(const Vehiculo vehiculos[], int num_vehiculos) {
    FILE *archivo = fopen(ARCHIVO_VEHICULOS, "w");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo para guardar.\n");
        return;
    }
    for (int i = 0; i < num_vehiculos; i++) {
        fprintf(archivo, "%s %s %s %s %.2f %.2f %.2f %d %.2f %.2f %d %.2f %d %.2f %d\n",
                vehiculos[i].placa, vehiculos[i].marca, vehiculos[i].modelo,
                vehiculos[i].tipo_combustible, vehiculos[i].km_por_galon_carretera,
                vehiculos[i].km_por_galon_ciudad, vehiculos[i].costo_gomas,
                vehiculos[i].km_gomas, vehiculos[i].costo_seguro_anual,
                vehiculos[i].costo_mantenimiento, vehiculos[i].km_mantenimiento,
                vehiculos[i].costo_vehiculo, vehiculos[i].vida_util_anos,
                vehiculos[i].depreciacion_anual, vehiculos[i].km_anuales_promedio);
    }
    fclose(archivo);
}

void cargar_datos_generales(DatosGenerales *dg) {
    FILE *archivo = fopen(ARCHIVO_DATOS_GENERALES, "r");
    if (archivo == NULL) {
        dg->costo_gasolina = 0.0;
        dg->costo_gasoil = 0.0;
        return;
    }
    fscanf(archivo, "%f %f", &dg->costo_gasolina, &dg->costo_gasoil);
    fclose(archivo);
}

void guardar_datos_generales(const DatosGenerales *dg) {
    FILE *archivo = fopen(ARCHIVO_DATOS_GENERALES, "w");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo para guardar datos generales.\n");
        return;
    }
    fprintf(archivo, "%.2f %.2f", dg->costo_gasolina, dg->costo_gasoil);
    fclose(archivo);
}

int buscar_vehiculo_por_placa(const Vehiculo vehiculos[], int num_vehiculos, const char *placa) {
    for (int i = 0; i < num_vehiculos; i++) {
        if (strcmp(vehiculos[i].placa, placa) == 0) {
            return i;
        }
    }
    return -1;
}

void crear_vehiculo() {
    Vehiculo vehiculos[MAX_VEHICULOS];
    int num_vehiculos = cargar_vehiculos(vehiculos);
    if (num_vehiculos >= MAX_VEHICULOS) {
        printf("Error: Limite de vehiculos alcanzado.\n");
        return;
    }
    Vehiculo nuevo_vehiculo;
    printf("\n--- Crear Nuevo Vehiculo ---\n");
    printf("Placa: "); scanf("%s", nuevo_vehiculo.placa);
    printf("Marca: "); scanf("%s", nuevo_vehiculo.marca);
    printf("Modelo: "); scanf("%s", nuevo_vehiculo.modelo);
    printf("Tipo de Combustible (Gasolina/Gasoil): "); scanf("%s", nuevo_vehiculo.tipo_combustible);
    printf("Km por galon en carretera: "); scanf("%f", &nuevo_vehiculo.km_por_galon_carretera);
    printf("Km por galon en ciudad: "); scanf("%f", &nuevo_vehiculo.km_por_galon_ciudad);
    printf("Costo de gomas: "); scanf("%f", &nuevo_vehiculo.costo_gomas);
    printf("Km de gomas: "); scanf("%d", &nuevo_vehiculo.km_gomas);
    printf("Costo de seguro anual: "); scanf("%f", &nuevo_vehiculo.costo_seguro_anual);
    printf("Costo de mantenimiento: "); scanf("%f", &nuevo_vehiculo.costo_mantenimiento);
    printf("Km de mantenimiento: "); scanf("%d", &nuevo_vehiculo.km_mantenimiento);
    printf("Costo del vehiculo: "); scanf("%f", &nuevo_vehiculo.costo_vehiculo);
    printf("Vida util (años): "); scanf("%d", &nuevo_vehiculo.vida_util_anos);
    printf("Depreciacion anual: "); scanf("%f", &nuevo_vehiculo.depreciacion_anual);
    printf("Km por año promedio: "); scanf("%d", &nuevo_vehiculo.km_anuales_promedio);
    vehiculos[num_vehiculos] = nuevo_vehiculo;
    guardar_vehiculos_en_archivo(vehiculos, num_vehiculos + 1);
    printf("\nVehiculo creado y guardado exitosamente.\n");
}

void borrar_vehiculo() {
    Vehiculo vehiculos[MAX_VEHICULOS];
    int num_vehiculos = cargar_vehiculos(vehiculos);
    char placa_a_borrar[10];
    printf("\n--- Borrar Vehiculo ---\n");
    printf("Ingrese la placa del vehiculo a borrar: ");
    scanf("%s", placa_a_borrar);
    int indice = buscar_vehiculo_por_placa(vehiculos, num_vehiculos, placa_a_borrar);
    if (indice != -1) {
        for (int i = indice; i < num_vehiculos - 1; i++) {
            vehiculos[i] = vehiculos[i+1];
        }
        guardar_vehiculos_en_archivo(vehiculos, num_vehiculos - 1);
        printf("Vehiculo con placa %s borrado exitosamente.\n", placa_a_borrar);
    } else {
        printf("No se encontro ningun vehiculo con esa placa.\n");
    }
}

void modificar_vehiculo() {
    Vehiculo vehiculos[MAX_VEHICULOS];
    int num_vehiculos = cargar_vehiculos(vehiculos);
    char placa_a_modificar[10];
    printf("\n--- Modificar Vehiculo ---\n");
    printf("Ingrese la placa del vehiculo a modificar: ");
    scanf("%s", placa_a_modificar);
    int indice = buscar_vehiculo_por_placa(vehiculos, num_vehiculos, placa_a_modificar);
    if (indice != -1) {
        printf("Vehiculo encontrado. Ingrese los nuevos datos:\n");
        printf("Marca: "); scanf("%s", vehiculos[indice].marca);
        printf("Modelo: "); scanf("%s", vehiculos[indice].modelo);
        guardar_vehiculos_en_archivo(vehiculos, num_vehiculos);
        printf("Vehículo modificado exitosamente.\n");
    } else {
        printf("No se encontro ningun vehiculo con esa placa.\n");
    }
}

void listar_vehiculos() {
    Vehiculo vehiculos[MAX_VEHICULOS];
    int num_vehiculos = cargar_vehiculos(vehiculos);
    if (num_vehiculos == 0) {
        printf("\nNo hay vehiculos registrados.\n");
        return;
    }
    printf("\n--- Lista de Vehiculos ---\n");
    for (int i = 0; i < num_vehiculos; i++) {
        printf("Vehiculo #%d\n", i + 1);
        printf("  Placa: %s\n", vehiculos[i].placa);
        printf("  Marca: %s\n", vehiculos[i].marca);
        printf("  Modelo: %s\n", vehiculos[i].modelo);
        printf("-------------------------\n");
    }
}

void actualizar_costos_combustible() {
    DatosGenerales dg;
    printf("\n--- Actualizar Costos de Combustible ---\n");
    printf("Ingrese el costo actual de la gasolina: ");
    scanf("%f", &dg.costo_gasolina);
    printf("Ingrese el costo actual del gasoil: ");
    scanf("%f", &dg.costo_gasoil);
    guardar_datos_generales(&dg);
    printf("Costos de combustible actualizados.\n");
}

void calcular_costo_viaje() {
    Vehiculo vehiculos[MAX_VEHICULOS];
    int num_vehiculos = cargar_vehiculos(vehiculos);
    DatosGenerales dg;
    cargar_datos_generales(&dg);
    char placa_seleccionada[10];
    float km_viaje, porcentaje_ciudad;
    int indice_vehiculo;
    if (num_vehiculos == 0) {
        printf("\nNo hay vehiculos para calcular el viaje. Por favor, registre uno primero.\n");
        return;
    }
    listar_vehiculos();
    printf("Ingrese la placa del vehiculo para el viaje: ");
    scanf("%s", placa_seleccionada);
    indice_vehiculo = buscar_vehiculo_por_placa(vehiculos, num_vehiculos, placa_seleccionada);
    if (indice_vehiculo == -1) {
        printf("Vehiculo no encontrado.\n");
        return;
    }
    printf("Ingrese los kilometros totales del viaje: ");
    scanf("%f", &km_viaje);
    printf("Ingrese el porcentaje de kilometros en ciudad (0-100): ");
    scanf("%f", &porcentaje_ciudad);
    float km_ciudad = km_viaje * (porcentaje_ciudad / 100.0);
    float km_carretera = km_viaje - km_ciudad;
    float costo_gomas_km = vehiculos[indice_vehiculo].costo_gomas / vehiculos[indice_vehiculo].km_gomas;
    float costo_seguro_km = vehiculos[indice_vehiculo].costo_seguro_anual / vehiculos[indice_vehiculo].km_anuales_promedio;
    float costo_mantenimiento_km = vehiculos[indice_vehiculo].costo_mantenimiento / vehiculos[indice_vehiculo].km_mantenimiento;
    float costo_depreciacion_km = vehiculos[indice_vehiculo].depreciacion_anual / vehiculos[indice_vehiculo].km_anuales_promedio;
    float galones_carretera = km_carretera / vehiculos[indice_vehiculo].km_por_galon_carretera;
    float galones_ciudad = km_ciudad / vehiculos[indice_vehiculo].km_por_galon_ciudad;
    float costo_combustible_galon = (strcmp(vehiculos[indice_vehiculo].tipo_combustible, "Gasolina") == 0) ? dg.costo_gasolina : dg.costo_gasoil;
    float costo_combustible_viaje = (galones_carretera + galones_ciudad) * costo_combustible_galon;
    float costo_gomas_viaje = costo_gomas_km * km_viaje;
    float costo_seguro_viaje = costo_seguro_km * km_viaje;
    float costo_mantenimiento_viaje = costo_mantenimiento_km * km_viaje;
    float costo_depreciacion_viaje = costo_depreciacion_km * km_viaje;
    float costo_total_viaje = costo_gomas_viaje + costo_seguro_viaje + costo_mantenimiento_viaje + costo_depreciacion_viaje + costo_combustible_viaje;
    float costo_por_km = costo_total_viaje / km_viaje;
    printf("\n--- Resultado del Calculo del Viaje ---\n");
    printf("Vehiculo: %s %s (%s)\n", vehiculos[indice_vehiculo].marca, vehiculos[indice_vehiculo].modelo, vehiculos[indice_vehiculo].placa);
    printf("Kilometros totales del viaje: %.2f km\n", km_viaje);
    printf("Porcentaje en ciudad: %.2f%%\n", porcentaje_ciudad);
    printf("\nDesglose de Costos:\n");
    printf("  Costo de gomas: %.2f\n", costo_gomas_viaje);
    printf("  Costo de seguro: %.2f\n", costo_seguro_viaje);
    printf("  Costo de mantenimiento: %.2f\n", costo_mantenimiento_viaje);
    printf("  Costo de combustible: %.2f\n", costo_combustible_viaje);
    printf("  Costo de depreciación: %.2f\n", costo_depreciacion_viaje);
    printf("\nCosto por Kilometro: %.2f\n", costo_por_km);
    printf("Costo Total del Viaje: %.2f\n", costo_total_viaje);
}

int main() {
    int opcion_principal, opcion_secundaria;
    do {
        printf("\n--- Sistema de Gestion de Gastos de Vehiculo ---\n");
        printf("1. Gestion de Vehiculo\n");
        printf("2. Gestion de Datos Generales\n");
        printf("3. Calcular Costo de Viaje\n");
        printf("4. Salir\n");
        printf("-----------------------------------------------\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion_principal);
        switch (opcion_principal) {
            case 1:
                do {
                    printf("\n--- Gestion de Vehiculo ---\n");
                    printf("1. Crear\n");
                    printf("2. Borrar\n");
                    printf("3. Modificar\n");
                    printf("4. Listar\n");
                    printf("5. Volver al menu principal\n");
                    printf("Ingrese una opcion: ");
                    scanf("%d", &opcion_secundaria);
                    switch (opcion_secundaria) {
                        case 1: crear_vehiculo(); break;
                        case 2: borrar_vehiculo(); break;
                        case 3: modificar_vehiculo(); break;
                        case 4: listar_vehiculos(); break;
                        case 5: break;
                        default: printf("Opcion no valida.\n");
                    }
                } while (opcion_secundaria != 5);
                break;
            case 2:
                actualizar_costos_combustible();
                break;
            case 3:
                calcular_costo_viaje();
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion_principal != 4);
    return 0;
}
