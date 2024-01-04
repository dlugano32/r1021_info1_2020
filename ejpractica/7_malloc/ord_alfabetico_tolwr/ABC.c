#include "ABC.h"

void ordenABC(char **adr,int cant)
{
	int i=0, j=0;
	char *aux=NULL;

       for(i=0; *(adr+i)!=NULL; i++)
       {
              strlwr(*(adr+i));
       }

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

void strlwr (char *str)
{
       int i=0;

       for(i=0; *(str + i)!='\0'; i++)
       {
              if(*(str + i)>='A' && *(str + i)<='Z')
              {
                     *(str + i)= *(str + i)+ ' ';
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
