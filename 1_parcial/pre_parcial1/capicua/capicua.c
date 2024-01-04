#include "mylib.h"

#define TAM 256

int main (void)
{
       char word[TAM];
       int validacion;

       //scanf("%s", word);
       fgets(word, TAM, stdin);

       validacion= palindromo (word);

       if(validacion==1)
       {
              printf("La palabra %s, es capicua.\n", word);
       }
       else
       {
              printf("La palabra %s, no es capicua \n", word);
       }
       
       return (0);
}
