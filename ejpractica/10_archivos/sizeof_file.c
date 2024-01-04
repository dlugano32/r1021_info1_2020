#include <stdio.h>

int main (int argc, char **argv)
{
       FILE *fp=NULL;

       fp=fopen(*(argv + 1) , "r");
       if(fp==NULL)
       {
              printf("Error al leer el archivo\n");
       }
       fputs("123456789", fp);
       fseek(fp, 0, SEEK_END);
       printf("Tamaño en memoria: %ld\n",ftell(fp));

       fclose(fp);


}