#include "mylib.h"

int main (int argc, char **argv)
{
       if(argc==2)
       {
              //VARIABLES
              int registros=0, i=0;
              struct mediciones **sensor;
              char *file_dat=NULL, *file_txt=NULL;

              FILE *fp;
              fp=fopen(*(argv+1), "r");
              if(fp==NULL)
              {
                     printf("No se pudo abrir el archivo\n");
                     return -1;
              }

              //CANTIDAD DE REGISTROS
              fseek(fp, 0, SEEK_END);
              registros=ftell(fp) / sizeof(struct mediciones); //CANTIDAD DE REGISTROS
              printf("La cantidad de registros: %d\n", registros);
              rewind(fp);

              //GUARDO LOS REGISTROS
              sensor= (struct mediciones **) malloc( sizeof(struct mediciones*) *registros );
              save_struct(fp, sensor, registros);
              fclose(fp);

              //ORDENO LOS DATOS
              ordenar_struct(sensor, registros);

              //IMPRIMO LOS DATOS
              imprimir_struct(sensor, registros);

              //GENERAR ARCHIVO
              file_out(&file_dat, *(argv+1), "-out.dat");

              //printf("%s\n", file_dat);

              //GUARDO LOS DATOS EN UN ARCHIVO DE SALIDA .DAT
              fp=fopen(file_dat, "w");
              if(fp==NULL)
              {
                     printf("No se pudo abrir el archivo\n");
                     return -1;
              }

              archivo_salida_dat(fp, sensor, registros);

              free(file_dat);
              fclose(fp);

              //GENERO ARCHIVO
              
              file_out(&file_txt, *(argv+1), "-out.txt");

              //GUARDO LOS DATOS EN UN ARCHIVO DE SALIDA .TXT
              fp=fopen(file_txt, "w");
              if(fp==NULL)
              {
                     printf("No se pudo abrir el archivo\n");
                     return -1;
              }
              
              archivo_salida_txt(fp, sensor, registros);

              free(file_txt);
              fclose(fp);

              //LIBERO MEMORIA
              for(i=0; i<registros; i++)
              {
                     free(*(sensor +i));
              }

              free(sensor);
       }
       else
       {
              printf("Cantidad de argumentos invalida\n");
              return -1;
       }

       return 0;
}