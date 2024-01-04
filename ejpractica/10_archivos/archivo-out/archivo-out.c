#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_out(char **, char*, const char*);

int main(int argc, char **argv)
{
       if(argc==2)
       {
              FILE *fp_in, *fp_out;
              char str[20], *file;

              fp_in=fopen(*(argv+1), "r");
              if(fp_in==NULL)
              {
                     printf("ERROR-No es posible abrir el archivo\n");
                     return -1;
              }

              file_out(&file, *(argv+1), "-out.txt");
              fp_out=fopen(file, "w");

              fgets(str, 20, fp_in); //Guardo algo en el nuevo archivo
              fputs(str, fp_out);

              free(file);
              fclose(fp_in);
              fclose(fp_out);
       }
       else
       {
              printf("ERROR-Cantidad de argumentos invalida\n");
              return -1;
       }
       return 0;
}

void file_out(char ** archivo, char*str, const char *fin)
{
       char *aux=NULL;
       int i=0;

       for(i=0; *(str+i)!='.'; i++){       }

       aux=(char*)malloc( i * sizeof(char) );
       
       for(i=0; *(str+i)!='.'; i++)
       {
              *(aux+i)=*(str+i);
       }
       *(aux+i)='\0';

       *archivo=(char *) malloc( sizeof(char) * (strlen(aux)+strlen(fin)+1) );
       strcpy(*archivo, aux);
       strcat(*archivo,fin);

       printf("%s\n", *archivo);
       free(aux);
}