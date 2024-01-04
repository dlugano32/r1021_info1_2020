#include "mylib.h"

void save_struct(FILE *fp, struct mediciones ** sensor, int cantidad)
{
       int i=0;
       struct mediciones aux;

       for(i=0; i<cantidad; i++)
       {
              sensor[i]=(struct mediciones *) malloc( sizeof(struct mediciones) );

              fread(&aux, sizeof(struct mediciones), 1, fp);
              
              sensor[i]->id= aux.id;
              sensor[i]->time= aux.time;
              sensor[i]->valor = aux.valor;
              strcpy(sensor[i]->unidad, aux.unidad);
       }
}

void ordenar_struct(struct mediciones ** sensor, int cantidad)
{
       struct mediciones *aux;
       int i=0, j=0;

       for(i=0; i<cantidad-1 ; i++)
       {
              for(j=0; j< (cantidad -i -1); j++ )
              {
                     if ( sensor[j]->id > sensor[j+1]->id ) 
                     {
                            aux = sensor[j];
                            sensor[j] = sensor[j+1];
                            sensor[j+1] = aux;
		       }
              }
       }
}

void imprimir_struct(struct mediciones ** sensor, int cantidad)
{
       int i=0;

       for(i=0; i<cantidad; i++)
       {
              printf("time:%d\tid=%d\tvalor=%0.2f%s\n", sensor[i]->time, sensor[i]->id, sensor[i]->valor, sensor[i]->unidad);
       }
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

void archivo_salida_dat(FILE * fp, struct mediciones ** sensor, int cantidad)
{
       int i=0;

       for(i=0; i<cantidad; i++)
       {
              fwrite(sensor[i], sizeof(struct mediciones), 1, fp);
       }
}

void archivo_salida_txt(FILE * fp, struct mediciones ** sensor, int cantidad)
{
       int i=0;

       for(i=0; i<cantidad; i++)
       {
              fprintf(fp,"time:%d\tid=%d\tvalor=%0.2f%s\n", sensor[i]->time, sensor[i]->id, sensor[i]->valor, sensor[i]->unidad);
       }
}