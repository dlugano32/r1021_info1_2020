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
       uchar x; //Char sin signo
       bin b; //struct de los bits
       hexa h; //struct de 4 bits (hexa)
}byte;

int main (void)
{
       byte n1;

       scanf("%hhd", &n1.x); //el hhd es para meter un unsigned char como decimal

       //IMPRIMIR TODOS LOS BITS DEL UCHAR
       puts("\nBinario:\n");
       printf("%x\n", n1.b.b7);
       printf("%x\n", n1.b.b6);
       printf("%x\n", n1.b.b5);
       printf("%x\n", n1.b.b4);
       printf("%x\n", n1.b.b3);
       printf("%x\n", n1.b.b2);
       printf("%x\n", n1.b.b1);
       printf("%x\n", n1.b.b0);

       //IMPRIMO TODO EN HEXA
       puts("\nHexa:");
       printf("%x\n", n1.h.h1);
       printf("%x\n", n1.h.h0);

       return 0;
}