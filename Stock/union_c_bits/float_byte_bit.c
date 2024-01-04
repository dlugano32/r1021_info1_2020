#include <stdio.h>

/*PROTOCOLO IEEE 754*/

typedef unsigned char uchar;

typedef struct 
{
       uchar f23:1;
       uchar f22:1;
       uchar f21:1;
       uchar f20:1;
       uchar f19:1;
       uchar f18:1;
       uchar f17:1;
       uchar f16:1;
       uchar f15:1;
       uchar f14:1;
       uchar f13:1;
       uchar f12:1;
       uchar f11:1;
       uchar f10:1;
       uchar f09:1;
       uchar f08:1;
       uchar f07:1;
       uchar f06:1;
       uchar f05:1;
       uchar f04:1;
       uchar f03:1;
       uchar f02:1;
       uchar f01:1;
       uchar e08:1;
       uchar e07:1;
       uchar e06:1;
       uchar e05:1;
       uchar e04:1;
       uchar e03:1;
       uchar e02:1;
       uchar e01:1;
       uchar s:1;

}bin;

typedef union 
{
       float num;
       uchar byte[4];
       bin b;
}flotante;

int main (void)
{
       flotante n1;

       printf("Ingrese un numero flotante\n");
       scanf("%f", &n1.num);

       printf("El numero ingresado es %f\n", n1.num);
       printf("----------------------------\n");
       printf("\nEl numero en bytes\n");
       printf("1 byte\t%x\n",n1.byte[3]);
       printf("2 byte\t%x\n",n1.byte[2]);
       printf("3 byte\t%x\n",n1.byte[1]);
       printf("4 byte\t%x\n",n1.byte[0]);
       printf("----------------------------\n");
       printf("\nEl numero en bits\n");
       printf("%x",n1.b.s);
       printf("%x",n1.b.e01);
       printf("%x",n1.b.e02);
       printf("%x",n1.b.e03);
       printf("%x",n1.b.e04);
       printf("%x",n1.b.e05);
       printf("%x",n1.b.e06);
       printf("%x",n1.b.e07);
       printf("%x",n1.b.e08);
       printf("%x",n1.b.f01);
       printf("%x",n1.b.f02);
       printf("%x",n1.b.f03);
       printf("%x",n1.b.f04);
       printf("%x",n1.b.f05);
       printf("%x",n1.b.f06);
       printf("%x",n1.b.f07);
       printf("%x",n1.b.f08);
       printf("%x",n1.b.f09);
       printf("%x",n1.b.f10);
       printf("%x",n1.b.f11);
       printf("%x",n1.b.f12);
       printf("%x",n1.b.f13);
       printf("%x",n1.b.f14);
       printf("%x",n1.b.f15);
       printf("%x",n1.b.f16);
       printf("%x",n1.b.f17);
       printf("%x",n1.b.f18);
       printf("%x",n1.b.f19);
       printf("%x",n1.b.f21);
       printf("%x",n1.b.f22);
       printf("%x",n1.b.f23);
       printf("\n");

       return 0;
}