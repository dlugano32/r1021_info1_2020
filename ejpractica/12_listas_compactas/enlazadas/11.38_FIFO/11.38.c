/*Desarrolle una FIFO de N elementos para datos del tipo int. Dicha FIFO debe
presentar la siguiente interfaz.
 struct fifo * fifoCreate (int N);
 Descripción: Crea la FIFO.
 Parámetros: Cantidad de elementos de la FIFO.
 Retorna: Puntero a la estructura de control de la FIFO. En caso de error
devuelve NULL.
 int fifoWrite (struct fifo *p, int *dataPtr, int dataSize);
 Descripción: Escribe datos en la FIFO.
 Parámetros:
■ Puntero a la estructura de control de la FIFO.
■ Puntero a los datos a escribir en la fifo.
■ Cantidad de elementos a escritos.
 Retorna: La cantidad de elementos escritos en la FIFO.
O retorna -1 si la cantidad de elementos es mayor
al tamaño definido cuando se la creó
 int fifoRead (struct fifo *p, int *dataPtr, int dataSize);
 Descripción: Lee datos de la FIFO.
 Parámetros:
■ Puntero a la estructura de control de la FIFO.
■ Puntero al buffer donde colocar los datos leídos.
■ Cantidad de elementos a leer.
 Retorna: La cantidad de elementos leídos en la FIFO
O retorna 0 si está vacía, y -1 si hubo cualquier
otro error.
 int fifoDestroy (struct fifo *p);
 Parámetros:
 Puntero a la estructura de control de la FIFO.
 Retorna:
 Cero en caso de éxito, -1 en el caso opuesto*/

#include "my.h"

int main (void)
{
       struct fifo *cola;
       int *dataPtr=NULL, *buffer=NULL, dataSize=0, aux=0, i=0;

       dataPtr= (int *)malloc( sizeof(int) );
       

       cola=fifoCreate (int N);

       printf("Ingrese datos de temperatura\n");
       do
       {      

              printf("Temperatura %d:\t", i+1);
              scanf("%d", &aux);

              if(aux!=0)
              {
                     *(dataPtr + i)=aux;
                     dataPtr=(int *) realloc(dataPtr, sizeof(int) * (i+2));
                     i++;
              }
       } while (aux!=0);
       dataSize=i;
       fifoWrite (cola, dataPtr, dataSize);

       buffer= (int *)malloc( sizeof(int) * dataSize);
       fifoRead (cola, buffer, dataSize);

       for(i=0; i<dataSize; i++)
       {
              printf("%d\n", buffer[i]);
       }

       
       free(buffer);
       free(dataPtr);

       return 0;
}