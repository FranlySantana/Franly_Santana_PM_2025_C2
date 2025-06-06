#include <stdio.h>
//Problema PS3.10

/*
Una empresa dedicada a la venta de localidades por teléfono e Internet maneja
seis tipos de localidades para un circo ubicado en la zona sur de la Ciudad de
México. Algunas de las zonas del circo tienen el mismo precio, pero se manejan
diferente para administrar eficientemente la asignación de los asientos. Los pre
cios de cada localidad y los datos referentes a la venta de boletos para la próxima
función se manejan de la siguiente forma:

Datos:L1, L2, L3, L4, L5 y L6
      CLA, y los CAN.

Donde:  L1, L2, L3, L4, L5 y L6 son variables de tipo real que representan los
precios de las diferentes localidades.
CLA y los CAN son variables de tipo entero que representan el tipo de localidad
y la cantidad de boletos, respectivamente, de la venta

Escribe un diagrama de flujo y el correspondiente programa en C que realice lo
siguiente:

    a. Calcule el monto correspondiente de cada venta.
    b. Obtenga el número de boletos vendidos para cada una de las localidades.
    c. Obtenga la recaudación total. */

void main(void)
{

    float  L1 = 25, L2 = 23, L3 = 20, L4 = 27, L5 = 30, L6 = 22;
    int  CLA;
    int  CAN1=0,CAN2=0,CAN3=0,CAN4=0,CAN5=0,CAN6=0;
    int  CBV;
    float monto_venta;
    float recaudacion_total = 0.0;
    printf("precios de las localidades:\n");
    //scanf("%f %f %f %f %f %f", &L1, &L2, &L3, &L4, &L5, &L6);
    printf("\nPrecio de la localidad L1: %f",L1," Pesos");
    printf("\nPrecio de la localidad L2: %f",L2," Pesos");
    printf("\nPrecio de la localidad L3: %f",L3," Pesos");
    printf("\nPrecio de la localidad L4: %f",L4," Pesos");
    printf("\nPrecio de la localidad L5: %f",L5," Pesos");
    printf("\nPrecio de la localidad L6: %f",L6," Pesos");

    printf("\nIngrese el tipo de localidad(1-6) o 0 para terminar: ");
    scanf("%d",&CLA);
    while(CLA){
   printf("Ingrese la cantidad de boletos para esta venta: ");
   scanf("%d",&CBV);

   switch(CLA){
    case 1:
        monto_venta = L1 * CBV;
        CAN1 += CBV;
        break;

        case 2:
        monto_venta = L2 * CBV;
        CAN2 += CBV;
        break;

        case 3:
        monto_venta = L3 * CBV;
        CAN3 += CBV;
        break;

        case 4:
        monto_venta = L4 * CBV;
        CAN4 += CBV;
        break;

        case 5:
        monto_venta = L5 * CBV;
        CAN5 += CBV;
        break;

        case 6:
        monto_venta = L6 * CBV;
        CAN6 += CBV;
        break;

        default:
        printf("\nTipo de localidad invalido, ingrese un NUM del 1 al 6\n");
        monto_venta = 0;

    }
    if (CLA >= 1 && CLA <= 6){
        printf("Monto de esta venta: %.2f pesos\n", monto_venta);
        recaudacion_total += monto_venta;
    }
    printf("\n\nIngrese el siguiente tipo de localidad: ");
    scanf("%d",&CLA);

}
printf("\nResumen se ventas\n");
printf("Boletos vendidos para localidad 1: %d\n",CAN1);
printf("Boletos vendidos para localidad 2: %d\n",CAN2);
printf("Boletos vendidos para localidad 3: %d\n",CAN3);
printf("Boletos vendidos para localidad 4: %d\n",CAN4);
printf("Boletos vendidos para localidad 5: %d\n",CAN5);
printf("Boletos vendidos para localidad 6: %d\n",CAN6);
printf("Recaudacion total: %.2f",recaudacion_total);
}
