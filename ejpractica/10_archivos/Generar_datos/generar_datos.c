#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MUESTRAS 30 //Cant de muestas

enum{TENSION, CORRIENTE, RESISTENCIA, FRECUENCIA, CAPACITANCIA, FUERZA, VELOCIDAD, TEMPERATURA};

struct mediciones
{
       int id;
       int time;
       float valor;
       char unidad[5];
};


int main(void)
{
       FILE *fp, *fp2;
       int i=0;
       struct mediciones sensor[MUESTRAS];
       
       fp=fopen("mediciones.dat", "w");
       if(fp==NULL)
       {
              printf("No se pudo abrir el archivo\n");
       }
       fp2=fopen("mediciones.txt", "w");
       if(fp2==NULL)
       {
              printf("No se pudo abrir el archivo\n");
       }

       srand(time(NULL));

       for(i=0; i<MUESTRAS; i++)
       {
              sensor[i].id=rand()%8;

              switch(sensor[i].id)
              {
                     case TENSION:
                                                 sensor[i].valor=(rand()%22000)/100.0; // De 0 a 220V con 2 decimales
                                                 strcpy(sensor[i].unidad,"V");
                                                 break;

                     case CORRIENTE:
                                                 sensor[i].valor=(rand()%2000)/100.0; //De 0 a 20A con 2 decimales
                                                 strcpy(sensor[i].unidad, "A");
                                                 break;
                     
                     case RESISTENCIA:
                                                 sensor[i].valor=(rand()%10000000); //De 0 a 10Mohm 
                                                 strcpy(sensor[i].unidad, "OHM");
                                                 break;

                     case FRECUENCIA: 
                                                 sensor[i].valor=(rand()%1000000000); //De 0 a 1GHz
                                                 strcpy(sensor[i].unidad, "Hz");
                                                 break;
                     
                     case CAPACITANCIA:
                                                 sensor[i].valor=(rand()%10000)/10.0; //De 1nF a 1mF
                                                 strcpy(sensor[i].unidad, "uF");
                                                 break;

                     case FUERZA:
                                                 sensor[i].valor=(rand()%100000)/100.0; //De 0 a 1000 N con dos decimales
                                                 strcpy(sensor[i].unidad, "N");
                                                 break;

                     case VELOCIDAD:
                                                 sensor[i].valor=(rand()%5000)/10.0; //De 0 a 500 m/s con un decimal
                                                 strcpy(sensor[i].unidad, "m/s");
                                                 break;

                     case TEMPERATURA:
                                                 sensor[i].valor=(rand()%100000)/100.0; //De 0 a 1000 °K con un decimal
                                                 strcpy(sensor[i].unidad, "°K");
                                                 break;
              }
              
              sensor[i].time= time (NULL) - rand()%1000; //Es el tiempo en segundos desde 1970 menos un rango de 0 a 1000s
              fprintf(fp2, "Id=%d\tValor=%0.2f%s\tTime=%d\n", sensor[i].id, sensor[i].valor, sensor[i].unidad, sensor[i].time );
       }       

       fwrite(&sensor, sizeof(struct mediciones) , MUESTRAS, fp);

       fclose(fp);
       fclose(fp2);
       return 0;

}