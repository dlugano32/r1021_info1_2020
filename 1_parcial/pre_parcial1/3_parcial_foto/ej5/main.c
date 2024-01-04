#include "mylib.h"

int main (int argc, char **argv)
{
       int i=0, cont=0;

       for(i=1; i<argc; i++)
       {
              if(palindromo(*(argv+i))==1)
              {
                     printf("La palabra %s es un palindromo\n", *(argv+i) );
                     cont++;
              }          
       }

       printf("La cantidad de palindromos son: %d\n", cont);
       printf("El porcentaje de palindromos: %0.2f\n",  ( (float)cont/(argc-1) ) *100);
}