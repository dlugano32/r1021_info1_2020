#include "mylib.h"

int CuantasVeces (char* str, char c, int *vec_r)
{
       int i=0, j=0;

       for(i=0, j=0; *(str + i)!='\0'; i++)
       {
              if(*(str + i)==c)
              {
                     *(vec_r+j)=i;
                     vec_r=(int*) realloc(vec_r, sizeof(int)* (j+2));
                     j++;
              }
       }

       *(vec_r + j)='\0';
       return j;
}