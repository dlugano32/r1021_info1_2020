#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define no 0
#define si 1
//COLA --->FIFO = first input first output

struct cola
{
        int buffer[MAX];
        int i_read;
        int i_write;
        int flag_lleno;
        int flag_vacio;
};

void cola_init( struct cola *);
int push (struct cola * , int);
int pop (struct cola* , int *);
int listar (struct cola*);
void eliminar_cola(struct cola *);
