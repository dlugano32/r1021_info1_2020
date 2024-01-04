/*2)Realizar una función con el siguiente prototipo:

int reemplazo(char *str1,char *str2, char car)
char *str1 es un puntero a char que contiene la dirección de inicio de una cadena de caracteres, 
char *str2 es un puntero a char que contiene la dirección de inicio de una cadena de caracteres, 
char car es un variable que contiene el caracter a reemplazar por 'X'

Retorna: 1 si se pudo reemplazar en la cadena de caracteres str1 el caracter dado y se guardó la información 
en la segunda cadena de caracteres, y 0 en caso contrario en un int*/
#include "replace.h"

int main(void)
{
       char *str1, *str2, car;
       char word1[N], word2[N];
       int condition;

       str1=word1;
       str2=word2;

       printf("Ingresar string\n");
       fgets(word1, N, stdin);
       printf("Ingresar caracter a reemplazar\n");
       setbuf(stdin, NULL);
       scanf("%c", &car);

       if (car>='A' && car<='Z')
       {
             car= car+ ' ';
       }
       
       condition=reemplazo(str1,str2,car);

        if(condition==1)
        {
               printf("El string original es : %s\n", str1);
               printf("El string modificado es: %s\n", str2);
        }
        else
              {
                     printf("No se pudo completar el proceso\n");
              }

       return(0);
}

