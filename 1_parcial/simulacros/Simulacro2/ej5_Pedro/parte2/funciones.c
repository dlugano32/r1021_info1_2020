#include "mylib.h"

unsigned char suma_saturada(unsigned char a, unsigned char b)
{
       unsigned char r=0;
       if(a+b>255)
       {
              r=255;
       }
       else
       {
              r=a+b;
       }
       
       return r;
}

unsigned char *suma_saturada_vector(unsigned char *vec1, unsigned char *vec2, unsigned int n)
{
       unsigned char *vec_r=NULL;
       int i=0;

       vec_r=(unsigned char*) malloc(sizeof(unsigned char) * n);

       for(i=0; i<n; i++)
       {
              *(vec_r +i)=suma_saturada(*(vec1+i), *(vec2+i));
       }

       return vec_r;
}