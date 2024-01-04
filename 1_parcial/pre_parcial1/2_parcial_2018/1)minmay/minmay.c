/*Dado el siguiente prototipo:
void minmay(int *vec, int tam, int lim);
Escribir una función que tome el vector de enteros (vec), su tamaño (tam) y un valor límite (lim). 
La función deberá indicar cuántos valores dentro del vector están por arriba del límite y cuantos están por debajo de el.
Deberá informar estos resultados por pantalla.*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void minmay(int *vec, int tam, int lim);

int main(void)
{
       int vec[TAM], i=0, valor=0;

       for(i=0; i<TAM; i++)
       {
              scanf("%d", &vec[i]);
       }

       printf("Ingrese valor limite:\n");
       scanf("%d", &valor);

       minmay(vec, TAM, valor );

       return (0);
}

void minmay(int *vec, int tam, int lim)
{
       int i=0, j=0, aux=0, sup=0;

       for(i=0; i<tam-1; i++ )
       {
              for(j=0; j<tam -i -1; j++)
              {
                     if(*(vec +j) > *(vec +(j+1)) )
                     {
                            aux=*(vec + j);
                            *(vec+j)=*(vec +(j+1));
                            *(vec+ (j+1))=aux;
                     }
              }
       }

       for(i=0; i<tam; i++)
       {
              if(*(vec+i)> lim)
              {
                     sup++;
              }
       }

       printf("La cantidad de valores por arriba del limite son: %d\n", sup);
}