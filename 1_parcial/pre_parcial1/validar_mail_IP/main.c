#include "validar.h"

int main (int argc, char** argv)
{

       int val=0;

       val=validar_CC( *(argv+1));

       printf("%d\n", val );

       return 0;
}