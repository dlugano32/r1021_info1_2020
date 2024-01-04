/*Realizar un función con prototipo:
unsigned int my_streq (char *str1, char *str2);
Esta función deberá determinar si la primer cadena es igual a la segunda. 
Si son iguales retornará verdadero y si son distintas puede retornar falso.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

unsigned int my_streq (char *, char *);

int main (void)
{
       char word1[TAM], word2[TAM];
       int validacion;

       fgets(word1, TAM, stdin);
       fgets(word2, TAM, stdin);

       validacion=my_streq(word1, word2);

       if(validacion==1)
       {
              printf("Los strings ingresados son iguales\n");
       }
       else
              {
                     printf("Los strings ingresados NO son iguales\n");
              }

       return 0;
}

unsigned int my_streq (char *str1, char *str2)
{
       int i=0;

       for(i=0; *(str1+i)!='\0' || *(str2+i)!='\0'; i++)
       {
              if(*(str1 +i ) != *(str2+i ))
              {
                     return 0;
              }
       }

       return 1;
}