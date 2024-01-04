#include "replace.h"

int reemplazo(char *str1,char *str2, char car)
{
       int i=0, cont=0;

       for(i=0; *(str1+i)!='\0'; i++)
       {
              if(*(str1+i)==car || *(str1+i)== (car - ' '))
              {
                     *(str2+i)='X';
                     cont++;
              }
              else
                     {
                            *(str2+i)=*(str1+i);
                     }
       }

       if(cont == 0)
       {
              return 0;
       }
       
       return 1;
}