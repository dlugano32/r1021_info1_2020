#include "mymalloc.h"

void sacar_enter(char *str, int length)
{
       if(*(str + (length -1) ) == 10) //pregunto si es enter la ultima posicion del string antes del null
       {
              length --;
              *(str + length ) = '\0'; //si tiene enter le pongo null arriba
       }
}

void liberar_memoria(char **vec)
{
       int i=0;

       for(i=0; *(vec + i)!=NULL; i++)
       {
              free ( *(vec + i) );
       }
       free (*(vec+ i)); //libero el NULL

       free(vec);
}

void imprimir_palabras(char **vec)
{
       int i=0;

       for(i=0; *(vec + i)!=NULL; i++)
       {
              printf("%s\n", *(vec + i) );
       }
}