#include "my.h"

void cola_init( struct cola *c )
{
        c->i_read=0;
        c->i_write=0;
        c->flag_lleno=no;
        c->flag_vacio=si;
}

void push (struct cola *c, struct mem dato)     //Escribo en la cola
{
        if(c->flag_lleno == si)
        {
                printf("Lista llena. Se sobreescribe el primer dato\n");
                c->i_read ++;           //Si la cola esta llena muevo el indice de lectura asi siempre leo los MAX ultimos datos
                c->i_read %= MAX;
        }

        //Guardo los datos en la cola
        c->buffer[c->i_write].MemFree=dato.MemFree;
        c->buffer[c->i_write].MemAvailable=dato.MemAvailable;
        c->buffer[c->i_write].SwapFree=dato.SwapFree;

        c->i_write++;
        c->i_write %=MAX;  //Si llego a la ultima posicion del buffer, devuelve 0.
        c->flag_vacio=no;       //Le acabo de escribir un dato-->No esta vacia

        if(c->i_write == c->i_read)
        {
                c->flag_lleno=si;
        }
}
