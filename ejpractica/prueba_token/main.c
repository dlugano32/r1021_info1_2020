#include <stdio.h>
#include <stdlib.h>


int main (void)
{
       char IP[ ]={"255.256.257.258"}, **IP_m=NULL, *p=NULL;
       int i=0, k=0, j=0;

       IP_m=(char **) malloc(sizeof(char *) * 4);

       for(j=0; j<4; j++)
       {
              p=(char *) malloc(sizeof(char) * 4);
              *(IP_m+j) = p;
              for(k=0; *(IP+i)!= '\0' && *(IP + i)!= '.' ; k++, i++)
              {
                     *(p+ k)= *(IP + i);
              }
              *(p+k)='\0';
              i++;
       }

       for(i=0; i<4; i++)
       {
              printf("%s\n", *(IP_m+i));
       }

       for(i=0; i<4; i++)
       {
              free( *(IP_m+i));
       }

       free(IP_m);

      return 0; 
}
