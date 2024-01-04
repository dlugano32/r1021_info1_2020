#include "mylib.h"

int main(void)
{
       char **ptr=NULL;
       char str[]={"From the depths of the sea, back to the block snoop doggy dogg, funky as the D.O.C"};
       printf("String original: ");
       puts(str);
       ptr=extraer_palabras(str);
       printf("Palabras:\n");
       imprimir_palabras(ptr);
       liberar_memoria(ptr);
       return(0);
}