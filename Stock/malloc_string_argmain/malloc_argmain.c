#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 256

int main (int argc, char **argv)
{
       char *p=NULL, **vec=NULL;
       int i=0, j=0, length=0;

       vec=(char**) malloc(sizeof(char *) * (argc-1) );
       if(vec==NULL)
       {
              printf("Error asignando memoria\n");
       }      

       for(i=1, j=0; i<argc; i++, j++)
       {
              length=strlen(*(argv+i));
              p=(char*)malloc(sizeof(char) * (length+1));
              if(p==NULL)
              {
                     printf("Error asignando memoria\n");
              }
              strcpy(p, *(argv+i));
              *(vec+j)=p;
       }

       for(i=0; i< (argc-1) ; i++)
       {
              printf("%s\n", *(vec + i) );
       }

       for(i=0; i< (argc-1) ; i++)
       {
              free(*(vec+i));
       }
       free(vec);
       
       return 0;
}