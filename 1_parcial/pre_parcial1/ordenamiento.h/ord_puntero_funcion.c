#include "mylib.h"

int main (void)
{
       void ( *function[2] )();
       int *vec, num=0, i=0, cant=0;

       vec= (int *) malloc(sizeof(int));

       function[0]=ascendente;
       function[1]=descendente;

       printf("Ingrese valores enteros, los mismos se guardaran en un vector. Cuando termine ingrese '0' \n");

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
       printf("\nIngrese ahora como desea ordenar al vector. [0] ascendente\t[1] descendente\n");
       scanf("%d", &num); //reutilizo variable nomas

       (*function[num])(vec, cant);

       for(i=0; i<cant ; i++)
       {
              printf("vec [%d] : %d\n", i , *(vec + i) );
       }

       free(vec);

       return (0);
}     