#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 100
#define no 0
#define si 1
//COLA --->FIFO = first input first output


struct Nodo {
float temp;
char fecha[8];
char hora[8];
};

struct cola
{
        struct Nodo buffer[MAX];
        int i_read;
        int i_write;
        int flag_lleno;
        int flag_vacio;
};

void cola_init( struct cola *);
void push (struct cola * , struct Nodo);
