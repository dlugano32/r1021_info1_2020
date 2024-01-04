#include "mylib.h"

int validaString(char *dataPtr)
{
       int i=0, r=0, cont_word=0, cont_num=0;

       for(i=0; *(dataPtr +i)!='\0'; i++)
       {
              if( (*(dataPtr +i )>='a' && *(dataPtr +i)<='z') || (*(dataPtr+i)>='A' && *(dataPtr+i)<='Z') )
              {
                     cont_word++;
              }
              else if(*(dataPtr+i)>='0' && *(dataPtr+i)<='9')
              {
                     cont_num++;
              }
       }

       if(strlen(dataPtr) == cont_word)
       {
              r=1;
       }
       else if(strlen(dataPtr) == cont_num)
       {
              r=2;
       }
       else
       {
              r=0;
       }
       
       return r;
}