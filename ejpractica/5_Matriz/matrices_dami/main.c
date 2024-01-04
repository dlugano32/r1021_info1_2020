#include <stdio.h>
#include <stdlib.h>

int main(void)
{
       int fila, columna, i=0, j=0;
       int **matriz=NULL, *p=NULL;

       printf("Ingrese filas y despues columnas\n");
       scanf("%d %d", &fila, &columna);
       
       matriz=(int **) malloc(sizeof(int*) * fila);

       for(i=0; i<fila; i++)
       {
              *(matriz + i)=(int*) malloc(sizeof(int) *columna );
       }

       for(i=0; i<fila; i++) // tomo datos
       {
              p=*(matriz+i);
              for(j=0; j<columna; j++)
              {
                     scanf("%d", p+j);
              }
       }

       for(i=0; i<fila; i++) //imprimo datos
       {
              p=*(matriz+i);
              printf("|\t");
              for(j=0; j<columna; j++)
              {
                     printf("%d\t", *(p+j) );
              }
              printf("|\n");
       }

       for(i=0; i<fila; i++) //libero memoria
       {
              free( *(matriz + i) );
       }

       free(matriz);

       return (0);
}