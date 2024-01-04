#include "my.h"

void save_struct(FILE *fp, struct mediciones** vec, int cant)
{
       int i=0;
       struct mediciones *aux, buffer;

       for(i=0; i<cant; i++)
       {
              aux=(struct mediciones *) malloc( sizeof(struct mediciones) );

              fread(&buffer, sizeof(struct mediciones), 1, fp);

              aux->id=buffer.id;
              aux->time=buffer.time;
              aux->valor=buffer.valor;
              strcpy(aux->unidad, buffer.unidad);
              *(vec + i)=aux;
       }
}

void ord_unidad (struct mediciones ** vec, int cant)
{
       struct mediciones *aux;
       int i=0, j=0;

       for(i=0; i<cant-1 ; i++)
       {
              for(j=0; j< (cant -i -1); j++ )
              {
                     if ( vec[j]->id > vec[j+1]->id ) 
                     {
                            aux = vec[j];
                            vec[j] = vec[j+1];
                            vec[j+1] = aux;
		       }
              }
       }
}

void ord_time (struct mediciones ** vec, int cant)
{
       struct mediciones *aux;
       int i=0, j=0;

       for(i=0; i<cant-1 ; i++)
       {
              for(j=0; j< (cant -i -1); j++ )
              {
                     if ( vec[j]->time > vec[j+1]->time ) 
                     {
                            aux = vec[j];
                            vec[j] = vec[j+1];
                            vec[j+1] = aux;
		       }
              }
       }
}

void imprimir_struct(struct mediciones ** vec, int cant)
{
       int i=0;

       for(i=0; i<cant; i++)
       {
              printf("time:%d\tid=%d\tvalor=%0.2f%s\n", vec[i]->time, vec[i]->id, vec[i]->valor, vec[i]->unidad);
       }
}

void file_out(char ** archivo, char*str, const char *fin)
{
       char *aux=NULL, *f_name=NULL;
       int i=0;

       for(i=0; *(str+i)!='.'; i++){       }

       aux=(char*)malloc( i * sizeof(char) );
       
       for(i=0; *(str+i)!='.'; i++)
       {
              *(aux+i)=*(str+i);
       }
       *(aux+i)='\0';

       f_name=(char *) malloc( sizeof(char) * (strlen(aux)+strlen(fin)+1) );
       strcpy(f_name, aux);
       strcat(f_name,fin);
       *archivo=f_name;
       printf("%s\n", *archivo);
       free(aux);
}

void archivo_salida_dat(FILE * fp, struct mediciones ** vec, int cant)
{
       int i=0;

       for(i=0; i<cant; i++)
       {
              fwrite(vec[i], sizeof(struct mediciones), 1, fp);
       }
}

void archivo_salida_txt(FILE * fp, struct mediciones ** vec, int cant, float prom)
{
       int i=0;

       for(i=0; i<cant; i++)
       {
              fprintf(fp,"time:%d\tid=%d\tvalor=%0.2f%s\n", vec[i]->time, vec[i]->id, vec[i]->valor, vec[i]->unidad);
       }
       fprintf(fp,"\nPromedio:%0.2f\n", prom);
}

float prom_tension (struct mediciones **vec , int registros)
{
       int i=0, n=0, acum=0;
       float prom;

       for(i=0; i<registros; i++)
       {
              if( vec[i]->id==0)
              {
                     acum=acum+vec[i]->valor;
                     n++;
              }
       }

       prom= (float) acum/n;
       printf("El promedio de la tension es \t%0.2fV\n\n", prom);
       return prom;
}

float prom_corriente (struct mediciones **vec , int registros)
{
       int i=0, n=0, acum=0;
       float prom;

       for(i=0; i<registros; i++)
       {
              if( vec[i]->id==1)
              {
                     acum=acum+vec[i]->valor;
                     n++;
              }
       }

       prom= (float) acum/n;
       printf("El promedio de la corriente es \t%0.2fA\n\n", prom);
       return prom;
}

float prom_resistencia (struct mediciones **vec , int registros)
{
       int i=0, n=0, acum=0;
       float prom;

       for(i=0; i<registros; i++)
       {
              if( vec[i]->id==2)
              {
                     acum=acum+vec[i]->valor;
                     n++;
              }
       }

       prom= (float) acum/n;
       printf("El promedio de la resistencia es \t%0.2fOHM\n\n", prom);
       return prom;
}

float prom_frecuencia (struct mediciones **vec , int registros)
{
       int i=0, n=0, acum=0;
       float prom;

       for(i=0; i<registros; i++)
       {
              if( vec[i]->id==3)
              {
                     acum=acum+vec[i]->valor;
                     n++;
              }
       }

       prom= (float) acum/n;
       printf("El promedio de la frecuencia es \t%0.2fHz\n\n", prom);
       return prom;
}

float prom_capacitancia (struct mediciones **vec , int registros)
{
       int i=0, n=0, acum=0;
       float prom;

       for(i=0; i<registros; i++)
       {
              if( vec[i]->id==4)
              {
                     acum=acum+vec[i]->valor;
                     n++;
              }
       }

       prom= (float) acum/n;
       printf("El promedio de la capacitancia es \t%0.2fuF\n\n", prom);
       return prom;
}

float prom_fuerza (struct mediciones **vec , int registros)
{
       int i=0, n=0, acum=0;
       float prom;

       for(i=0; i<registros; i++)
       {
              if( vec[i]->id==5)
              {
                     acum=acum+vec[i]->valor;
                     n++;
              }
       }

       prom= (float) acum/n;
       printf("El promedio de la fuerza es \t%0.2fN\n\n", prom);
       return prom;
}

float prom_velocidad (struct mediciones **vec , int registros)
{
       int i=0, n=0, acum=0;
       float prom;

       for(i=0; i<registros; i++)
       {
              if( vec[i]->id==6)
              {
                     acum=acum+vec[i]->valor;
                     n++;
              }
       }

       prom= (float) acum/n;
       printf("El promedio de la velocidad es \t%0.2fm/s\n\n", prom);
       return prom;
}

float prom_temp (struct mediciones **vec , int registros)
{
       int i=0, n=0, acum=0;
       float prom;

       for(i=0; i<registros; i++)
       {
              if( vec[i]->id==7)
              {
                     acum=acum+vec[i]->valor;
                     n++;
              }
       }

       prom= (float) acum/n;
       printf("El promedio de la temperatura es \t%0.2fK\n\n", prom);
       return prom;
}

