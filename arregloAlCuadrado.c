#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

struct arregloAlCuadrado
{
    int *arreglo;
    int par;
    int impar;
    
};


bool memoriaDinamicaArreglo(int *elementos,struct arregloAlCuadrado *array){

    array->arreglo = (int *) malloc(*elementos*sizeof(int));
    
    return array->arreglo==NULL;
}

void * arregloCuadrado(void *arg){

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

    if(elementos % 2 == 0)
        array.par=elementos/2;
    else{
        array.par=array.impar=elementos/2;
        array.impar++;
    }

    pthread_create(&hilo1,NULL,arregloCuadrado,(void *)&array);
    pthread_create(&hilo2,NULL,arregloCuadrado,(void *)&array);
   



    return 0;
}