/*Realizar las funciones (incluyendo una función) main donde se imprimirán los resultados tal que
ingresando por linea de comandos grupos de 6 palabras se imprima:
• La cantidad de caracteres.
• La cantidad de vocales.
• Y la cantidad de consonantes de cada palabra.
Deberá controlar que se hayan ingresado la cantidad de argumentos correcta y emitir un mensaje en caso
de no serlo y pedir el reingreso.*/

#include "mylib.h"

int main(int argc, char **argv)
{
       int i=0;

       if(argc==7)
       {      
              for(i=1; i<argc; i++ )
              {
                     printf("La palabra '%s' tiene:\n", *(argv+i));
                     caracteres(*(argv+i));
                     vocales(*(argv+i));
                     consonantes(*(argv+i));
                     printf("\n");
              }
       }
       else
       {
              printf("Cantidad de argumentos incorrecta por favor ingreselos de nuevo\n");
       }
       
       

       return 0;
}