#include <stdio.h>

int main(void) 
{
       int i;
       char buffer[] = {0x45, 0xAA, 0x25, 0x90};
       for (i=0 ; i < sizeof(buffer) ; i++)
       {
              printf("%x\t%d\r\n", buffer[i], buffer[i]);
       }
       puts("");
       return(0);
 }