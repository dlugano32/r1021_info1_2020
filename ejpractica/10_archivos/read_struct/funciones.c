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