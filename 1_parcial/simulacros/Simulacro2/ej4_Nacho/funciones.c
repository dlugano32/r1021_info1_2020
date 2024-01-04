#include "mylib.h"

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

void liberar_memoria(char **vec)
{
       int i=0;
       for(i=0; *(vec + i)!=NULL; i++)
       {
              free ( *(vec + i) );
       }
       free (*(vec+ i)); //libero el NULL

       free(vec);
}

