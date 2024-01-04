/*4) Realizar una función que aplique el algoritmo de un filtro de media móvil. La función recibe un puntero al inicio de un array de floats con los valores de entrada, 
y puntero al inicio de otro array de floats para guardar los valores de salida, además del largo total del array. El algoritmo consiste en promediar L muestras, 
desde la muestra i, y guardar el resultado en el elemento i del array de salida. Cuando se procesen los últimos L elementos del array de entrada, considerar que los 
valores que no existen son cero.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 2

void filtro(float *, float *, int) ;

int main(void)
{
       int i=0, N=5;
       float vec1[N], vec2[N];

       for(i=0; i<N; i++)
       {
              scanf("%f", &vec1[i]);
       }

       filtro(vec1, vec2, N);

       for(i=0; i<N; i++)
       {
              printf("%0.2f\n", vec2[i]);
       }
       

       return(0);
}

void filtro(float *vec1, float *vec2, int N)
{
       int i=0, j=0;
       float aux=0;

       for(i=0; i<N; i++)
       {
              for(j=i, aux=0; j<(i+L) ; j++)
              {
                     if(j<N)
                     {
                            aux=aux+ *(vec1+j);
                     }
              }
              *(vec2+i)=aux/L;
       }
}