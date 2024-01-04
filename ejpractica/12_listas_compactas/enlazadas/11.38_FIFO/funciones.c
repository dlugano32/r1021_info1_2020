#include "my.h"

struct fifo * fifoCreate (int N)
{
       struct fifo cola;
       int *vec;

       vec=(int *) malloc( sizeof(int) *N );
       if(vec==NULL)
       {
              printf("ERROR - En la asignacion de memoria");
              return NULL;
       }
       cola.input=vec;
       cola.output=vec;

       return &cola;
}

int fifoWrite (struct fifo *p, int *dataPtr, int dataSize);
{
       int i=0;

       if(dataSize>N)
       {
              printf("ERROR - Cantidad de datos mayor al tamaño de la cola\n");
              return -1;
       }
       else
       {
              for(i=0; i<dataSize; i++)
              {
                     *(p->input) = dataPtr[i];
                     (p->input)++;
              }
       }

       return i;
}

int fifoRead (struct fifo *p, int *dataPtr, int dataSize)
{
       int i=0;

       do
       {
              dataPtr[i]= *(p->output);
              (p->output)++;
              i++;
       }while(p->input != p->output);

       return i;
}

int fifoDestroy (struct fifo *p)
{
       
}