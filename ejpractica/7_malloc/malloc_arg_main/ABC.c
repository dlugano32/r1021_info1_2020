#include "ABC.h"

void ordenABC(char **vec_s, int cant)
{
       int i,j;
       char *aux;

       for(i=0; i<(cant-1); i++)
       {
              for(j=i+1; j<(cant-1); j++)
              {
                     if(strcmp(*(vec_s+i),*(vec_s+j)) > 0)
                     {
                         aux=*(vec_s+i);
                         *(vec_s+i)=*(vec_s+j);
                         *(vec_s+j)=aux;
                     }
              }
       }
}

void  imprimir(char **vec_s, int cant)
{
       int j=0;

       for(j=0; j<(cant-1) ; j++) //argc-1 es la cantidad de palabras que entran por argumento, sin contar el nombre del prog
       {
              printf("%s\n", *(vec_s+j));
       }
}