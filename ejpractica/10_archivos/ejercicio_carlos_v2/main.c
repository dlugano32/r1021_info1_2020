/*   Crear un registro usando vector de memoria dinámica.
   Ordenar el registro según par o impar número random.
   Generar nombre para un nuevo archivo de salida.
   Crear un nuevo archivo de salida y guardar el contenido del registro ordenado*/

#include "my.h"

int main (int argc, char **argv)
{
       if (argc==2)
       {
              FILE *fp;
              int registros=0, i=0;
              float prom;
              char *file_dat=NULL, *file_txt=NULL;
              uchar mask1, mask2;
              struct mediciones **vec=NULL;
              union byte choice;
              void (*funciones_1 [2])()={ord_unidad, ord_time};
              float (*funciones_2 [8])()={prom_tension, prom_corriente, prom_resistencia, prom_frecuencia, prom_capacitancia, prom_fuerza, prom_velocidad, prom_temp};

              fp=fopen(*(argv + 1), "r");
              if(fp==NULL)
              {
                     printf("ERROR - No se pudo abrir el archivo\n");
              }

              /*CANTIDAD DE REGISTROS*/
              fseek(fp, 0, SEEK_END);
              registros= ftell(fp) / sizeof(struct mediciones);
              printf("Cantidad de registros: %d\n", registros);
              rewind(fp);

              /*GUARDAR STRUCT*/
              vec=( struct mediciones **) malloc(registros * sizeof(struct mediciones *) );
              save_struct(fp, vec, registros);
              fclose(fp);

              /*ORDENO LA STRUCT*/
              srand(time(NULL));
              choice.x=rand()%255;
              printf("Numero random: %x\n", choice.x);
              printf("%x%x%x%x %x%x%x%x\n", choice.b.b7, choice.b.b6, choice.b.b5, choice.b.b4, choice.b.b3, choice.b.b2,choice.b.b1, choice.b.b0 );

              mask1=choice.x & 0x01; // xxxx xxxx and 0000 0001
              mask2=choice.x &0x07; // xxxx xxxx and 0000 0111

              //Si el bit = 1 --> orden_time
              //Si el bit = 0 --> orden_unidad
              if(!mask1)
              {
                     printf("Se ordenó los registros segun su unidad\n\n");
              }
              else
              {
                     printf("Se ordenó los registros segun su time_stap\n\n");
              }

              (*funciones_1[mask1])(vec, registros); //invoco a la funcion de ordnamiento dependiendo del ultimo bit*/
              prom=(*funciones_2[mask2])(vec, registros);      

              /*IMPRIMO STRUCT*/
              imprimir_struct(vec, registros);              

              /*GENERAR ARCHIVO*/
              file_out(&file_dat, *(argv+1), "-out.dat");

              /*GUARDO LOS DATOS EN UN ARCHIVO DE SALIDA .DAT*/
              fp=fopen(file_dat, "w");
              if(fp==NULL)
              {
                     printf("No se pudo abrir el archivo\n");
              }

              archivo_salida_dat(fp, vec, registros);

              free(file_dat);
              fclose(fp);

              /*GENERO ARCHIVO*/
              
              file_out(&file_txt, *(argv+1), "-out.txt");

              /*GUARDO LOS DATOS EN UN ARCHIVO DE SALIDA .TXT*/
              fp=fopen(file_txt, "w");
              if(fp==NULL)
              {
                     printf("No se pudo abrir el archivo\n");
              }
              
              archivo_salida_txt(fp, vec, registros, prom);

              free(file_txt);
              fclose(fp);

              /*LIBERO MEMORIA*/
              for(i=0; i<registros; i++)
              {
                     free(*(vec +i));
              }

              free(vec);
       }      
       else
       {
              printf("ERROR - Cantidad de argumentos incorrectas\n");
       }

       return 0;
}