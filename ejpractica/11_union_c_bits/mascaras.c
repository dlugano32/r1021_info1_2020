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

typedef union 
{
       uchar x; //Char sin signo
       bin b; //struct de los bits
}byte;

int main (void)
{
       byte n1;
       uchar mask_nl, mask_nh, mask_ms, mask_ls, mask_aa;
       int choice;
       
       /*EN UN BYTE*/
       mask_nl=0x0F; //nibble inferior
       mask_nh=0xF0; //nibble superior
       mask_ms=0x80; //most significant bit 
       mask_ls=0x01; //less significant bit
       mask_aa=0xAA; //b1010´1010

       printf("Ingrese que mascara quiere hacer: \n[1]nibble_l\n[2]nibble_h\n[3]most significant bit on\n[4]less significant bit on\n[5]xor con 0xaa = b10101010\n[6]NOT\n");
       scanf("%d", &choice);

       printf("Ingrese numero:\n");
       scanf("%hhd", &n1.x); //el hhd es para meter un unsigned char como decimal
       printf("\nBinario\n");
       printf("%x", n1.b.b7);
       printf("%x", n1.b.b6);
       printf("%x", n1.b.b5);
       printf("%x", n1.b.b4);
       printf("%x", n1.b.b3);
       printf("%x", n1.b.b2);
       printf("%x", n1.b.b1);
       printf("%x\n", n1.b.b0);

       switch(choice)
       {
              case 1: 
                            n1.x=n1.x&mask_nl; //AND -> MASCARA PARA SACAR EL NIBBLE INFERIOR   //mask_nl=0x0F; //b0000'1111
                            break;

              case 2: 
                            n1.x=n1.x&mask_nh; //AND -> MASCARA PARA SACAR EL NIBBLE SUPERIOR  //mask_nh=0xF0; //b1111'0000
                            break;
              
              case 3: 
                            n1.x=n1.x | mask_ms; //OR -> MASCARA para prender el bit mas significativo //mask_ms=0x80; //b1000'0000
                            break;
              
              case 4: 
                            n1.x=n1.x | mask_ls; //OR ->MASCARA para prender el bit menos significativo //mask_Ls=0x1; //b0000'0001
                            break;
                     
              case 5: 
                            printf("xor\n10101010\n"); //numero random para ver como funcionaba la xor
                            n1.x=n1.x^ mask_aa; //XOR con 0xAA//B1010'1010
                            break;

              case 6: 
                            n1.x=~n1.x; //NOT
                            break;

              default: printf("Argumento incorrecto\n");
                            return -1;
       }
       

       //IMPRIMIR TODOS LOS BITS DEL UCHAR
       printf("\nMask:\n");
       printf("%x", n1.b.b7);
       printf("%x", n1.b.b6);
       printf("%x", n1.b.b5);
       printf("%x", n1.b.b4);
       printf("%x", n1.b.b3);
       printf("%x", n1.b.b2);
       printf("%x", n1.b.b1);
       printf("%x\n", n1.b.b0);

       return 0;
}