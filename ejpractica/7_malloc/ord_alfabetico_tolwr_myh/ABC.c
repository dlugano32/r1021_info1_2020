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
			if ((my_strcmp(*(adr+i),*(adr+j)) > 0))
			{
				aux= *(adr+j);
				*(adr+j)= *(adr+i);
				*(adr+i)=aux;
			}
		}
	}
}

void my_strcpy (char *destino , char *origen) //OJO con la memoria
{
       int i=0;

       for(i=0; *(origen +i)!='\0'; i++)
       {
              *(destino +i)= *(origen+i);
       }

       *(destino+i)='\0';
}

int my_strlen (char *str)
{
       int i=0;

       while(*(str+i)!='\0')
       {
              i++;
       }

       return i;
}

int my_strcmp (char *str1, char *str2)
{
       int fin=1, dif=0, i=0;

       while ( (*(str1 +i) == *(str2 + i) ) && fin==1)
       {
              if(*(str1 +i) == '\0' && *(str2 + i)=='\0')
              {
                     dif=0;
                     fin=0;
              }
              i++;
       }

       if(fin ==1)
       {
              dif= *(str1+i) - *(str2+i);
       }

       return dif;
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
