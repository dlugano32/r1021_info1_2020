/*3. Escribir una función que recibe un vector de 1024 bytes con una cadena (de estilo C). 
Esta función deberá devolver un nuevo vector con una copia de la cadena ingresada. 
Pero el vector devuelto debe tener solamente el tamaño necesario para alojar la cadena.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * my_malloc(char *);

int main(void)
{
       char word[1024];
       char *p;

       fgets(word, 1024, stdin);

       p=my_malloc(word);

       printf("%s\n",p);

       free(p);

       return(0);
}

char * my_malloc(char *str)
{
       char *p;
       int length;

       length= (int)strlen(str);
       *(str+ (length-1))='\0';// le saco el 0xa
       p=(char *)malloc(sizeof(char) *  length);
       strcpy(p, str);
       return p;
}