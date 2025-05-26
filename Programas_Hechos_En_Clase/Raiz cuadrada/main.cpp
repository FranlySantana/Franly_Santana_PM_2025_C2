#include <iostream>

using namespace std;

int main()
{
    float x = 0;
    float b = 0;
    int cnt = 1;

    printf("\nIngrese el valor: ");
    scanf("%f",&x);

    b = x;

    while(! (b == (x/b))){

        printf("\nValor de b[%i]:%f",cnt,b);

        b = 0.5 * ((x/b)+b);

        cnt ++;
    }

    printf("\nLa raiz cuadrada de %f es: %f ",x,b);

    return 0;
}
