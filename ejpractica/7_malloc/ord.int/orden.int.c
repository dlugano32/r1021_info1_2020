#include "int.h"

int main (void)
{      
       char num[N], c;
       int i=0, *vec;
       size_t length;

       vec=(int *) malloc (sizeof(int) );

       do
       {
              fgets(num, N, stdin);
              length=strlen(num);
              *(num+(length-1))='\0';
              length--;     //borro el enter (0xa)

              c=*num;
              
              if(c!='.')
              {
                     *(vec+i)=atoi(num);

                     vec=(int *)realloc(vec, (i+2) * sizeof(int));
              }
              else
                     {
                            *(vec+i)='\0';
                     }
              
              i++;

       } while (c!='.');//hasta que se ingrese un punto
       
       orden_vec(vec);
       imprimir(vec);

       free(vec);

       return (0);
}