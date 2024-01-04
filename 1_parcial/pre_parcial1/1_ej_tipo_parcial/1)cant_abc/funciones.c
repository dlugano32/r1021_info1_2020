#include "cant_ABC.h"

void cant_ABC(char *word, int *vec)
{
       int i=0, j=0;
       char c;

       for(i=0; *(word+i)!='\0' ; i++)
       {
              c=*(word+i);
            for(j=0; j<25; j++)
            {
                   if(c=='a'+j || c=='A'+j) //hago un contador por letra y le voy sumando j para que vaya cambiando letra por pasada
                   {
                          vec[j]=vec[j]+1;
                   }
            }
       }
}

void  imprimir(int *vec)
{
	int j=0;
	
	for(j=0; j<25 ; j++)
      {
             if(*(vec+j) !=0)
             {
		       printf("Cantidad de %c: %d\n", 'a'+j, *(vec+j));
             }
      }
}