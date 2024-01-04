#include "mylib.h"

int main (void)
{
       char word[256];
       int length=0, val=0;

       fgets(word, 256, stdin);
       length=strlen(word);
       *(word+ (length-1))='\0';

       val=validaString(word);

       if(val==1)
       {
              printf("El string %s contiene solo letras\n", word);
       }
       else if(val ==2)
       {
              printf("El string %s contiene solo numeros\n", word);
       }
       else
       {
              printf("El string  %s NO contiene solo letras o solo numeros\n", word);
       }
       


       return 0;
}