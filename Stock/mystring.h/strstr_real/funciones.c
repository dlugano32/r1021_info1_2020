#include "mylib.h"

char* my_strstr (char *big, char *sub)
{
       int i=0, j=0, pos=0, length=0;
       char *ret=NULL;

       while(*(big+i)!='\0')
       {
              i++;
       }
       length=i;

       if(*(big + (length -1) ) == 10) //pregunto si es enter la ultima posicion del string antes del null
       {
              length --;
              *(big+ length ) = '\0'; //si tiene enter le pongo null arriba
       }

       i=0;//vuelvo a poner el contador en 0

       while(*(sub+i)!='\0')
       {
              i++;
       }
       length=i;

       if(*(sub + (length -1) ) == 10) //pregunto si es enter la ultima posicion del string antes del null
       {
              length --;
              *(sub+ length ) = '\0'; //si tiene enter le pongo null arriba
       }

       for(i=0, j=0; *(big +i)!='\0' && ret==NULL; i++)
       {
              if(*(big+i) == *(sub+j))//si hay tantas coincidencias seguidas con el largo del substring entonces es valido
              {
                     j++;
                     if(j==1)
                     {
                            pos=i;
                     }
              }
              else
              {
                     j=0;
              }

              if(j==length) //pregunto si la cantidad de coincidencias que hubo con el string es igual al largo
              {
                     ret=NULL;
                     ret= big + pos;
              }   
       }

       return ret;
}