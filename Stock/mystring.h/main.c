#include "mystring.h"

int main (void)
{
       char haystack[TAM]={"Paralelepipedo"};
       char needle[TAM]={"le"};
       int val=0;

       val=my_strstr(haystack, needle);

       printf("%d\n", val );
       
       return 0;
}