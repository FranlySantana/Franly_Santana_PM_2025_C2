#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5];
    a[0]=34;
    a[1]=125;
    a[2]=5;
    a[3]=4;
    a[4]=66;

    for (int i = 0; i<5; i++){
      printf("\nValor de a[%i]=%i",i,a[i]);
    }
    return 0;
}
