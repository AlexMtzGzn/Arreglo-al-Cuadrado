#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

struct arregloAlCuadrado
{
    int recorrido;
    int *arreglo;
};


bool memoriaDinamicaArreglo(int *elementos,struct arregloAlCuadrado *array){

    array->arreglo = (int *) malloc(*elementos*sizeof(int));
    
    return array->arreglo==NULL;
}

void * arregloCuadro(void *arg){

}

int main(void){

    pthread_t hilo1,hilo2;
    int elementos;

    struct arregloAlCuadrado array;

    printf("\nIngresa la cantidad de elementos del arreglo: ");
    scanf("%i",&elementos);

   if(memoriaDinamicaArreglo(&elementos,&array) == NULL){
        perror("Error al asignar memoria en el arreglo");
        return -1;
    }


    }
    
   



    return 0;
}