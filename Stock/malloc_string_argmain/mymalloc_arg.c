#include "mymalloc_arg.h"

void liberar_memoria(char **vec, int cant)
{
       int j=0;

       for(j=0; j<cant ; j++)
       {
              free(*(vec+j));
       }
       free(vec);
}

void imprimir_palabras(char **vec, int cant)
{
       int i=0;

       for(i=0; i<cant; i++)
       {
              printf("%s\n", *(vec + i) );
       }
}