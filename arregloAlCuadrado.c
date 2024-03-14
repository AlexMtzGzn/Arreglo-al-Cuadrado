#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

struct arregloAlCuadrado
{
    int inicio;
    int final;
};

int *memoriaDinamicaArreglo(int *elementos, int *arreglo)
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

    posiciones[0].inicio = 0;

    if (elementos % 2 == 0)
    {

        posiciones[0].final = posiciones[1].inicio = elementos / 2;
        posiciones[1].final = elementos;
    }
    else
    {
    }

    pthread_create(&hilo1, NULL, arregloCuadrado, (void *)&array);
    pthread_create(&hilo2, NULL, arregloCuadrado, (void *)&array);

    pthread_join(&hilo1, NULL);
    pthread_join(&hilo2, NULL);

    return 0;
}