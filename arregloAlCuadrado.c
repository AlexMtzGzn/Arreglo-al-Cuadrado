#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int * memoriaDinamicaArreglo(int *elementos){

    int arreglo = (int *) malloc(*elementos*sizeof(int));

    return arreglo;
}

int main(void){

    pthread_t hilo1,hilo2;
    int elementos, *arreglo; 

    printf("\nIngresa la cantidad de elementos del arreglo: ");
    scanf("%i",&elementos);


    arreglo = memoriaDinamicaArreglo(&elementos);



    return 0;
}