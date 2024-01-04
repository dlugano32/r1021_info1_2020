#include "mylib.h"

void imprimirNombres(char **vec)
{
       int i=0;

       for(i=0; *(vec + i)!=NULL; i++)
       {
              printf("%s\n", *(vec + i) );
       }
}

void ascendente(char **adr,int cant)
{
	int i=0, j=0;
	char *aux=NULL;

	for(i=0; *(adr+i)!=NULL; i++)
	{
		for(j=i+1;*(adr+j)!=NULL ; j++)
		{
			if ((strcmp(*(adr+i),*(adr+j)) > 0))
			{
				aux= *(adr+j);
				*(adr+j)= *(adr+i);
				*(adr+i)=aux;
			}
		}
	}
}

void descendente(char **adr,int cant)
{
	int i=0, j=0;
	char *aux=NULL;

	for(i=0; *(adr+i)!=NULL; i++)
	{
		for(j=i+1;*(adr+j)!=NULL ; j++)
		{
			if ((strcmp(*(adr+i),*(adr+j)) < 0))
			{
				aux= *(adr+j);
				*(adr+j)= *(adr+i);
				*(adr+i)=aux;
			}
		}
	}
}