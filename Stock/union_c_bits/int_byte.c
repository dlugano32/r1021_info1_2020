#include <stdio.h>

union four_b
{
       int x;
       char b[4];
};

int main(void)
{
       union four_b n1;

       n1.x=0x10203040; //variable entera de 4 bytes en hexa

       printf("%x\n", n1.b[3]); //Imprimo byte a byte
       printf("%x\n", n1.b[2]);
       printf("%x\n", n1.b[1]);
       printf("%x\n", n1.b[0]);
       
       return 0;
}      