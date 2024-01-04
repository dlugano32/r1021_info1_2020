/*1) Realizar una función que reciba una cadena de caracteres en ASCII de hasta 8192 caracteres. La función deberá leer la cadena y determinar 
(ignorando la diferencia entre mayusculas y minusculas) la cantidad de veces que se repite cada caracter del abecedario. El programa terminará mostrando
 por pantalla (de la A a la Z sin la ñ) que cantidad de ocurrencias de cada letra se encontró dentro de la cadena de caracteres recibida.*/

#include "cant_ABC.h"

int main (void)
{
       char word[N], *word_up=NULL;
       size_t length;
       int ABC[25], j=0;
       for(j=0; j<25; j++)//inicializo el vector en 0
       {
              ABC[j]=0;
       }

       fgets(word, N, stdin);
       length=strlen(word);
       word_up=(char *)malloc(sizeof(char) * length);
       strcpy(word_up,word);

       if(word_up==NULL)
       {
              printf("ERROR");
       }
       else
              {
                     cant_ABC(word_up, ABC);
                     imprimir(ABC);
              }
       
       free(word_up);
       return 0;
}
