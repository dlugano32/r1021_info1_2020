/*Escribir un programa que utilizando las funciones ya desarrolladas e incluidas en
una librería, convierta un archivo de texto a minúsculas o mayúsculas,
dependiendo de la selección hecha por el usuario:
Uso: chgcase <path archivo origen> <path archivo destino> <formato>
en donde el formato puede ser:
-u : a mayúsculas (UPPERCASE)
-l : a minúsculas (LOWERCASE) */
#include "11.8.h"

int main (int argc, char **argv)
{
       if(argc==2)
       {
              char *f_out, choice[3];

              FILE *fp, *fp2;
              fp=fopen(*(argv+1), "r");
              if(fp==NULL)
              {
                     printf("ERROR - El archivo no se pudo abrir\n");
                     return -1;
              }

              printf("Archivo ingresado:\t%s\n", *(argv+1));
              printf("Quiere convertirlo a:\n -u: Mayusculas\n -l: Minusculas\n");
              scanf("%s", choice);

              file_out(&f_out, *(argv+1), "-out.txt"); //Es una funcion que genera un archivo de salida, vacio, con el mismo nombre que el de entrada
              fp2=fopen(f_out, "w");
              if(fp2==NULL)
              {
                     printf("ERROR - El archivo no se pudo abrir\n");
                     return -1;
              }

              chgcase (fp, fp2, choice);

              free(f_out);

       }
       else
       {
              printf("ERROR - Cantidad de argumentos incorrecta\n");
       }
       return 0; 
}