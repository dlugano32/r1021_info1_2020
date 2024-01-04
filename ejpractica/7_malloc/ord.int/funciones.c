#include "int.h"

void orden_vec(int *vec)
{
       int i=0, j=0, aux=0;

       for(i=0; *(vec+i)!='\0'; i++)
       {
			for(j=i+1; *(vec+j)!='\0'; j++)
			{
				if(*(vec+i) > *(vec+j))
				{
					aux=*(vec+i);
					*(vec+i)= *(vec+j);
					*(vec+j)=aux;
				}
			}
       }
}

void  imprimir(int *vec)
{
	int j=0;
	
	for(j=0; *(vec+j)!='\0' ; j++)
      {
		printf("%d\n", *(vec+j));
      }
}
