#include "11.16_lib.h"

int main (int argc, char **argv)
{

       if(argc==4) //para que solo se puedan ingresar la cantidad justo de argumentos
       {
              FILE *f_in, *f_out;
              int i=0, j=0, cant_campos=0, cont=0, flag=0, n_campo=0;
              char str[TAM], *ptr=NULL;

              f_in=fopen(*(argv+1), "r"); //Abro en modo lectura el archivo de los datos
              if(f_in == NULL)
              {
                     printf("ERROR - No se pudo abrir el archivo");
                     return -1;
              }
              
              fseek(f_in, 0, SEEK_END);

              if( ftell(f_in) != 0) //Para que verifique si el archivo de entrada está vacio
              {
                     /*VERIFICO EL ARCHIVO DE ENTRADA*/
                     rewind(f_in);

                     for(j=0; !feof(f_in); j++, cont=0)
                     {
                            fgets(str, TAM, f_in); //voy leyendo de a una linea de un tamaño maximo de 16K caracteres(lo especificaba el ejercicio)

                            if(j==0) //Tomo de la primer linea, la cantidad de comas que deberian tener todas las demas lineas
                            {
                                   for(i=0; *(str +i)!='\0'; i++)
                                   {
                                          if(*(str + i) == ',')
                                          {
                                                 cant_campos++;
                                          }
                                   }
                            }

                            if( j>0 )
                            {
                            for(i=0; *(str +i)!='\0'; i++)
                                   {
                                          if(*(str + i) == ',')
                                          {
                                                 cont++;
                                          }
                                   }

                                   if(cont != cant_campos) //si alguna linea tiene menos comas (menos campos) no lo valido
                                   {
                                          printf("ERROR EN EL ARCHIVO DE INGRESOS, CANTIDAD DE CAMPOS INCONSISTENTES\n");
                                          flag=1; //flag de error

                                   }
                            }              
                     }

                     rewind(f_in); //retrocedo el cursor del archivo para poder trabajar desde el principio
                     cont=j; //cantidad de registros.
                     cant_campos++; //al contar la cantidad de comas, la cantidad de campos existentes en el archivo,  es la cantidad de comas +1
                     n_campo=atoi(*(argv+2)); //Guardo el numero de campo que quiero extraer

                     /*IMPRIMO LOS DATOS SOLICITADOS EN EL ARCHIVO DE SALIDA*/
                     if( (flag!=1) && (cant_campos >= n_campo) && ( n_campo > 0) ) // compruebo que el flag no se haya disparado, y que el numero de campo solicitado sea consistente con la cantidad de campos que existen en el archivo
                     {
                            f_out=fopen(*(argv+3), "w"); //abro el archivo de salida
                            if(f_out == NULL)
                            {
                                   printf("ERROR - No se pudo abrir el archivo");
                                   return -1;
                            }

                            for(i=0; i<cont; i++, ptr=NULL) 
                            {
                                   fgets(str, TAM, f_in); //Vuelvo a tomar de a una linea, ahora para buscar el campo requerido

                                   ptr=strtok(str, ","); // tomo el string hasta la primera coma

                                   if( n_campo > 1) //si el numero de campo es mayor a 1 sigo haciendo tokens
                                   {
                                          for(j=1; j< n_campo; j++)
                                          {
                                                 ptr=strtok(NULL, ",");
                                          }
                                   }

                                   fprintf(f_out, "%s\n", ptr); //Imprimo en el archivo
                            }

                            fclose(f_out);
                     }
                     else
                     {
                            printf("Cantidad de campos ingresados no valida\n");
                     }

                     fclose(f_in);
              }
              else
              {
                     printf("ERROR - El archivo de entrada esta vacio\n");
              }
              
       }
       else
       {
              printf("Cantidad de argumentos no valida, deben ser del tipo ./main <archivo de entrada> <número de campo> <archivo de salida>\n");
       }

       return 0;
}