#include "ABC.H"

void ordenABC(char **adr,int cant)
{
	int i=0, j=0;
	char *aux;
	
	for(i=0; i<cant; i++)
	{
		for(j=i+1; j<cant; j++)
		{
			if ((strcmp(*(adr+i),*(adr+j))) > 0)
			{
				aux= *(adr+j);
				*(adr+j)= *(adr+i);
				*(adr+i)=aux;
			}
		}
	}
}

void imprimir_nombres(char **adr)
{
	int i=0;
	
	for(i=0; *(adr+i)!=NULL; i++)
	{
		printf("%s\n",*(adr+i));
	}
}
