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