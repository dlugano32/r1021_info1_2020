#include "mylib.h"

void ascendente(int *vec, int cant)
{
       int i=0, j=0, aux=0;

       for(i=0; i<cant-1 ; i++)
       {
              for(j=0; j< (cant -i -1); j++ )
              {
                     if (vec[j] < vec[j+1]) 
                     {
                            aux =  vec[j];
                            vec[j] = vec[j+1];
                            vec[j+1] = aux;
		       }
              }
       }
}

void descendente(int *vec, int cant)
{
       int i=0, j=0, aux=0;

       for(i=0; i<cant-1 ; i++)
       {
              for(j=0; j< (cant -i -1); j++ )
              {
                     if (vec[j] > vec[j+1]) 
                     {
                            aux =  vec[j];
                            vec[j] = vec[j+1];
                            vec[j+1] = aux;
		       }
              }
       }
}
