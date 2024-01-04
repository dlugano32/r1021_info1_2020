#include "my.h"

int palindromo (char *word)
{
       int i=0, j=0, length=0, r=1;
       char *p=NULL;

       length=strlen(word);

       if(*(word + (length -1) ) == 10) //pregunto si es enter la ultima posicion del string antes del null
       {
              length --;
              *(word + length ) = '\0'; //si tiene enter le pongo null arriba
       }

       for(i=0; *(word+i)!='\0'; i++)
       {
              if( *(word+i)>= 'A' && *(word+i)<='Z')
              {
                     *(word+i)=*(word+i)+' ';
              }
       }

       p= (char*) malloc(sizeof(char) * (length+1) );
       
       for(i=0, j= (length-1) ; i < length ; i++, j--)
       {
              *(p+i)=*(word+j); //copio en p el string invertido
       }

       *(p+length)='\0'; //set NULL


       for(i=0; *(word+i)!='\0'; i++)
       {
              if( *(word+i) != *(p+i) )
              {
                     r=0;
              }
       }

       free(p);

       return r;        //si retorna 1 es capicua-> else not
}