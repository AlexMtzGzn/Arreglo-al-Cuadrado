#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

struct arregloAlCuadrado
{
   int inicio;
   int final;
};

bool memoriaDinamicaArreglo(int *elementos, struct arregloAlCuadrado *array)
{

    array->arreglo = (int *)malloc(*elementos * sizeof(int));

    return array->arreglo == NULL;
}

void *arregloCuadrado(void *arg)
{
    struct arregloAlCuadrado *array = (void *)arg;

    if (array->par == array->impar)
    {
    }
    else
    {
    }
}

int main(void)
{

    pthread_t hilo1, hilo2;
    int elementos;

    struct arregloAlCuadrado posiciones;

    printf("\nIngresa la cantidad de elementos del arreglo: ");
    scanf("%i", &elementos);

    if (memoriaDinamicaArreglo(&elementos, &array) == NULL)
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