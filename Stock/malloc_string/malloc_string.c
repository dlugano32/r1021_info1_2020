#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 256

int main(void)
{
       char c, str[TAM], *p=NULL, **vec=NULL;
       int i=0, length=0;

       vec=(char**) malloc(sizeof(char*));
       if(vec==NULL)
	{
		printf("ERROR ASIGNANDO MEMORIA\n");
	}

       do
       {
              fgets(str, TAM, stdin);
              length=strlen(str);
              length --;
              *(str + length) = '\0'; //le pongo null arriba del enters
              

              p= (char*) malloc(sizeof(char) * (length+1) );
              if(p==NULL)
	       {
		       printf("ERROR ASIGNANDO MEMORIA\n");
	       }
              strcpy(p, str);
              *(vec+i)=p;
              c=*p; //guardo el primer caracter del string en c

              if (c != '/')
              {
                    vec=(char **) realloc(vec, sizeof(char*) * (2+i)); //reservo memoria para el proximo string
                     if(vec==NULL)
	              {
	              	printf("ERROR ASIGNANDO MEMORIA\n");
                     }
              }
              else
                     {
                            free(p);
                            *(vec+i)='\0';
                     }

              i++;
       }
       while (c !='/');


       for(i=0; *(vec + i)!=NULL; i++)
       {
              printf("%s\n", *(vec + i) );
       }

       for(i=0; *(vec + i)!=NULL; i++)
       {
              free ( *(vec + i) );
       }
       free (*(vec+ i)); //libero el NULL

       free(vec);

       return (0);
}