#include <stdio.h>

typedef unsigned char uchar;

typedef struct
{
       uchar b0:1;
       uchar b1:1;
       uchar b2:1;
       uchar b3:1;
       uchar b4:1;
       uchar b5:1;
       uchar b6:1;
       uchar b7:1;
}bin;


typedef struct
{
     uchar h0:4;
     uchar h1:4;
}hexa;

typedef union
{
       int x;
       bin b[4];
       hexa h[4];
}four_b;

int main (void)
{
       int i=0;
       four_b n1;

       scanf("%d", &n1.x);

       //IMPRIMO LOS 4 BYTES EN BINARIO
       printf("\nBinario\n");
       for(i=3; i>-1; i--)
       {
              printf("%x byte:\t", i+1);
              printf("%x", n1.b[i].b7);
              printf("%x", n1.b[i].b6);
              printf("%x", n1.b[i].b5);
              printf("%x", n1.b[i].b4);
              printf("%x", n1.b[i].b3);
              printf("%x", n1.b[i].b2);
              printf("%x", n1.b[i].b1);
              printf("%x\n", n1.b[i].b0);
       }

       //IMPRIMO 4 BYTES EN HEXA
       printf("\nHexa\n");
       for(i=3; i>-1; i--)
       {      
              printf("%d byte:\t", i+1);
              printf("%x", n1.h[i].h1);
              printf("%x\n", n1.h[i].h0);
       }

       return 0;
}