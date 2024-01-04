#include "my.h"

void cola_init( struct cola *c )
{
        c->i_read=0;
        c->i_write=0;
        c->flag_lleno=no;
        c->flag_vacio=si;
}

void push (struct cola *c, struct Nodo dato)     //Escribo en la cola
{
        if(c->flag_lleno == si)
        {
                printf("Lista llena. Se sobreescribe el primer dato\n");
                c->i_read ++;
                c->i_read %= MAX;
        }

        c->buffer[c->i_write].temp=dato.temp;
        strcpy(c->buffer[c->i_write].fecha, dato.fecha);
        strcpy(c->buffer[c->i_write].hora, dato.hora);
        
        c->i_write++;
        c->i_write %=MAX;  //Si llego a la ultima posicion del buffer, devuelve 0.
        c->flag_vacio=no;       //Le acabo de escribir un dato-->No esta vacia

        if(c->i_write == c->i_read)
        {
                c->flag_lleno=si;
        }
}