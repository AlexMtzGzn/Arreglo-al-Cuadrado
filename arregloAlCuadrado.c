#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

struct arregloAlCuadrado
{
   int inicio;
   int final;
};

int * memoriaDinamicaArreglo(int *elementos, int *arreglo)
{

    arreglo = (int *)malloc(*elementos * sizeof(int));

    return arreglo;
}

void *arregloCuadrado(void *arg)
{
   
}

int main(void)
{

    pthread_t hilo1, hilo2;
    int elementos, arreglo;

    struct arregloAlCuadrado posiciones[2];

    printf("\nIngresa la cantidad de elementos del arreglo: ");
    scanf("%i", &elementos);

    if (arreglo = memoriaDinamicaArreglo(&elementos, &arreglo) == NULL)
    {
        perror("Error al asignar memoria en el arreglo");
        return -1;
    }

    array.inicio_hilo_1=0;

    if (elementos % 2 == 0)
    {

        array.final_hilo_1 = array.inicio_hilo_2 = elementos / 2;
    }
    else
    {
        array.par = array.impar = elementos / 2;
        array.impar++;
    }

    pthread_create(&hilo1, NULL, arregloCuadrado, (void *)&array);
    pthread_create(&hilo2, NULL, arregloCuadrado, (void *)&array);

    pthread_join(&hilo1, NULL);
    pthread_join(&hilo2, NULL);

    return 0;
}