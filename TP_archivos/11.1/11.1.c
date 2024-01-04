#include "11.1.h"

int main(void)
{
       FILE *fp;
       char str[TAM];
       int x=0, i=0, diodo=0;

       fp=fopen("file.txt", "r");
       if(fp==NULL)
       {
              printf("ERROR - No se ha podido abrir el archivo\n");      
              return -1;
       }

       do
       {
              x=fscanf(fp, "%s", str);

              if(x!=EOF)
              {
                     if( strcmp(str, "diodo")==0 )
                     {
                            diodo++;
                     }
                     i++;
              }
              
       }while(x!=EOF);

       printf("Cantidad de palabras: %d\nCantidad de veces que se repite la palabra 'diodo': %d\n", i, diodo);

       fclose(fp);
       return 0;
}