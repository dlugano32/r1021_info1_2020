#include "my.h"

void file_out(char ** archivo, char*str, const char *fin)
{
       char *aux=NULL;
       int i=0;

       for(i=0; *(str+i)!='.'; i++){       }

       aux=(char*)malloc( i * sizeof(char) );
       
       for(i=0; *(str+i)!='.'; i++)
       {
              *(aux+i)=*(str+i);
       }
       *(aux+i)='\0';

       *archivo=(char *) malloc( sizeof(char) * (strlen(aux)+strlen(fin)+1) );
       strcpy(*archivo, aux);
       strcat(*archivo,fin);
       free(aux);
}