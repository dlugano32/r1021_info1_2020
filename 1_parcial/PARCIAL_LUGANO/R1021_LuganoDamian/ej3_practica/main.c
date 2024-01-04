#include "mylib.h"

int main (void)
{
       char str[TAM];
       int length=0;
       char *ret;

       printf("Ingrese un string y se le asignara un espacio de memoria exacto para su longitud\n");

       fgets(str, TAM, stdin);
       length=strlen(str);
       length --;
       *(str + length) = '\0'; //le pongo null arriba del enter

       ret=copiaStr(str);
       printf("\nEl string ingresado es %s\n", ret);

       free(ret);

       return 0;
}