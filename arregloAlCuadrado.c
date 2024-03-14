#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

struct arregloAlCuadrado
{
    int inicio;
    int final;
};

int *arreglo;

void memoriaDinamicaArreglo(int *elementos)
{

    arreglo = (int *)malloc(*elementos * sizeof(int));
}
void imprimirArreglo(int *elementos){

     for(int i = 0; i < *elementos; i++)
        printf("%i  ",arreglo[i]);
}
void llenarArreglo(int *elementos){

    for(int i = 0; i < *elementos; i++){
        arreglo[i] = i;
    }
}

void *arregloCuadrado(void *arg)
{
    struct arregloAlCuadrado *posicion = (struct arregloAlCuadrado *)arg;

    for (int i = posicion->inicio; i < posicion->final; i++)
    {
        arreglo[i] *= arreglo[i];
    }

    pthread_exit(NULL);
}

int main(void)
{

    pthread_t hilo1, hilo2;
    int elementos;

    struct arregloAlCuadrado posiciones[2];

    printf("\nIngresa la cantidad de elementos del arreglo: ");
    scanf("%i", &elementos);

    memoriaDinamicaArreglo(&elementos);

    if (arreglo == NULL)
    {
        perror("Error al asignar memoria en el arreglo");
        return -1;
    }


    llenarArreglo(&elementos);

    printf("\n\nArreglo sin Cuadrado\n\n");

    imprimirArreglo(&elementos);

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

    imprimirArreglo(&elementos);

    free(arreglo);

    return 0;
}