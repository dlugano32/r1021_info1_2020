#include "mylib.h"

int main (void)
{
       int i=0, cant=0, num=0, umbral=0, *vec=NULL;

       vec= (int *) malloc(sizeof(int));

       do
       {
              scanf("%d", &num );

              if(num != 0)
              {
                     *(vec +i)=num;
                     vec= (int *) realloc(vec, sizeof(int) * (i+2));
                     i++;
              }      
       }
       while(num != 0);
       cant=i;

       printf("Ingrese el umbral minimo de aceptacion de valores\n");
       scanf("%d", &umbral);
       printf("La cantidad de valores que superan al umbral es: %d\n", ObtenerMayores(vec, cant, umbral) );

       free(vec);

       return 0;
}