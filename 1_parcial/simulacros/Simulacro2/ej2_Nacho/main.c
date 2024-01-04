#include "validar.h"

int main (int argc, char **argv )
{
       float **matriz=NULL;
       int i=0, j=0, k=0, val=0;
       char *p=NULL;

       for(i=0; i<(argc-1); i++)
       {
              val= val + validar(*(argv+ (i+1)) );
       }

       if(val==0)
       {
              matriz=(float **) malloc(sizeof(float*) * FILAS );

              for(i=0; i<FILAS; i++)
              {
                     *(matriz +i)= (float*) malloc( sizeof(float) * COLUMN);
              }

              for(i=0; i< FILAS; i++)
              {
                     p=*(argv + (i+1)); //guardo una fila

                     for(j=0; *(p+j)!=';'; j++){ }

                     matriz[i][0]=myAtof( p , j ); //a myAtof le paso el puntero del string y el largo// j es el largo de la primer componente, hasta el ;

                     for(k=0; *(p+ (j+k+1) )!='\0'; k++) { } //una vez parado con el puntero p en el ; le sumo 1 para estar parado en el primer numero de la segunda componente, y de ahi voy contando hasta llegar al NULL

                     matriz[i][1]=myAtof( p+ (j+1) , k); //es  p+ (j+1) porque le paso la posicion del primero numero decimal, k es el largo de la segunda componente
              }

              for(i=0; i<FILAS; i++)
              {
                     for(j=0; j<COLUMN; j++)
                     {
                            printf("Matriz [%d][%d]=%f\n",i ,j, matriz[i][j]);
                     }
              }

              printf("El producto escalar= %f\n", producto_escalar(matriz) );
              liberar_memoria(matriz, FILAS, COLUMN);
       }
       else
       {
              printf("Datos incorrectos\n");
       }

       return 0;
}