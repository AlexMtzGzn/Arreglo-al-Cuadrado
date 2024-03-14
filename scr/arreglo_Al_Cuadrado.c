#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct arregloAlCuadrado
{
    int *arreglo;
    int inicio;
    int final;
};

void memoriaDinamicaArreglo(int *elementos, int **arreglo)
{
    *arreglo = (int *)malloc(*elementos * sizeof(int));
}

void imprimirArreglo(int *elementos,int **arreglo){

     for(int i = 0; i < *elementos; i++)
        printf("%i  ",(*arreglo)[i]);
}

void llenarArreglo(int *elementos,int **arreglo){

    for(int i = 0; i < *elementos; i++)
        (*arreglo)[i] = i+1;
}

void *arregloCuadrado(void *arg)
{
    struct arregloAlCuadrado *posicion = (struct arregloAlCuadrado *)arg;

    for (int i = posicion->inicio; i < posicion->final; i++)
        posicion->arreglo[i] *= posicion->arreglo[i];

    pthread_exit(NULL);
}

int main(void)
{

    pthread_t hilo1, hilo2;
    int elementos, *arreglo;

    struct arregloAlCuadrado posiciones[2];

    printf("\nIngresa la cantidad de elementos del arreglo: ");
    scanf("%i", &elementos);

    memoriaDinamicaArreglo(&elementos,&arreglo);

    if (arreglo == NULL)
    {
        perror("Error al asignar memoria en el arreglo");
        return -1;
    }


    llenarArreglo(&elementos,&arreglo);

    printf("\n\nArreglo sin Cuadrado\n\n");

    imprimirArreglo(&elementos,&arreglo);

    posiciones[0].arreglo=arreglo;
    posiciones[1].arreglo=arreglo;

    posiciones[0].inicio = 0;

    if (elementos % 2 == 0)
    {

        posiciones[0].final = posiciones[1].inicio = elementos / 2;
        posiciones[1].final = elementos;
    }
    else
    {
        posiciones[0].final = posiciones[1].inicio = elementos / 2;
        posiciones[1].inicio++;
        posiciones[1].final = elementos;
    }

    if(pthread_create(&hilo1, NULL, arregloCuadrado, (void *)&posiciones[0]) != 0){
        perror("\nError al crear el hilo.");
        return -1;
    }
    
    if(pthread_create(&hilo2, NULL, arregloCuadrado, (void *)&posiciones[1]) != 0){
        perror("\nError al crear el hilo.");
        return -1;
    }

    if(pthread_join(hilo1, NULL) != 0){
        perror("\nError al esperar el hilo.");
        return -1;
    }

    if(pthread_join(hilo2, NULL) != 0){
        perror("\nError al esperar el hilo.");
        return -1;
    }

    printf("\n\nArreglo al Cuadrado\n\n");

    imprimirArreglo(&elementos,&arreglo);

    free(arreglo);

    return 0;
}