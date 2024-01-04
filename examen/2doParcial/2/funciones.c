#include "my.h"

void file_out(char ** archivo, char*str,  char *fin)
{
       char *aux=NULL;
       int i=0;

       for(i=0; *(str+i)!='\0'; i++){       }           //Cuento el largo del string

       aux=(char*)malloc( i * sizeof(char) );
       
       for(i=0; *(str+i)!='\0'; i++)
       {
              *(aux+i)=*(str+i);        //Copio str para no modificarlo
       }
       *(aux+i)='\0';

       *archivo=(char *) malloc( sizeof(char) * (strlen(aux)+strlen(fin)+1) );
       strcpy(*archivo, aux);
       strcat(*archivo,fin);

       free(aux);
}