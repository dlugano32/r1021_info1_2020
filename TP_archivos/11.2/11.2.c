#include "11.2.h"

int main (void)
{
       FILE *fp;
       int flag=0;
       char word[TAM];

       fp=fopen("file-out.txt", "w");
       if(fp==NULL)
       {
              printf("ERROR - No se pudo abrir el archivo\n");
              return -1;
       }

       printf("Ingrese caracteres y se imprimiran en el archivo con un salto de linea entre los mismos. Cuando termine ingrese un -1\n");
       do
       {
              fgets(word, TAM, stdin );

              if(strcmp(word, "-1\n")!=0) //EL -1 representa al EOF, tiene -1\n porque el fgets toma los \n
              {
                     fprintf(fp,"%s", word);
              }
              else
              {
                     flag=1;
              }
       
       }while(flag !=1);
       
       fclose(fp);

       return 0;
}