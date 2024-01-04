#include "mylib.h"

int main (void)
{
       int i=0, j=0, fila=0, **matriz=NULL, *p=NULL;
       float resultado[2];

       do
       {
              printf("Ingresar cantidad menor a 10 de vectores bidimensionales:\n");
              scanf("%d", &fila);
       } while (fila>10);

       matriz=(int **) malloc(sizeof(int*) * fila);

       for(i=0; i<fila; i++)
       {
              *(matriz + i)= (int *) malloc(sizeof(int) * 2);
       }

       for(i=0; i<fila; i++)
       {
              p=*(matriz + i);
              for(j=0; j<2; j++)
              {
                     scanf("%d", p+j);
              }
       }

       promedio(matriz, fila, resultado);

       for(i=0; i<2; i++)
       {
              printf("%f\n", *(resultado + i));
       }

       for(i=0; i<fila; i++) //libero memoria
       {
              free( *(matriz + i) );
       }

       free(matriz);


       return 0;
}