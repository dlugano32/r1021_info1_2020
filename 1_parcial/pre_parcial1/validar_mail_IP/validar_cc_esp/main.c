#include "mylib.h"

int main (void)
{

       int val=0;
       char cc[]={"7084 1461 0282 2041"}; 

       val=validar_CC( cc);

       printf("%d\n", val );

       return 0;
}