#include "mylib.h"

int main (void)
{
       int i=0;
       unsigned char *vec_r=NULL;
       unsigned char vec1[N]={255, 34, 56, 20};
       unsigned char vec2[N]={30, 33, 43, 255};
       vec_r=suma_saturada_vector(vec1, vec2, N);

       for(i=0; i<N; i++)
       {
              printf("%d\n", *(vec_r+i));
       }
       free(vec_r);
}