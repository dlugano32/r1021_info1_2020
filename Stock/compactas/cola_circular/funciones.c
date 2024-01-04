#include "cola.h"

void cola_init( struct cola *c )
{
        c->i_read=0;
        c->i_write=0;
        c->flag_lleno=no;
        c->flag_vacio=si;
}

void push (struct cola *c, int dato)     //Escribo en la cola
{
        if(c->flag_lleno == si)
        {
                printf("Lista llena. Se sobreescribe el primer dato\n");
                c->i_read ++;
                c->i_read %= MAX;
        }

        c->buffer[c->i_write]=dato;
        c->i_write++;
        c->i_write %=MAX;  //Si llego a la ultima posicion del buffer, devuelve 0.
        c->flag_vacio=no;       //Le acabo de escribir un dato-->No esta vacia

        if(c->i_write == c->i_read)
        {
                c->flag_lleno=si;
        }
}

int pop (struct cola *c, int *dato)
{
        if( (c->i_read==c->i_write) && (c->flag_lleno ==no) )
        {
                c->flag_vacio=si;
        }
        
        if(c->flag_vacio==si)
        {
                return 1;
        }
        
        *dato=c->buffer[c->i_read];
        c->i_read++;
        c->i_read %= MAX;
        c->flag_lleno=no;       //Si lei un dato no esta mas llena la cola

        return 0;
}

int listar (struct cola *c)
{
        int i=0, j=0;

        if( (c->i_read==c->i_write) && (c->flag_lleno ==no) )
        {
                c->flag_vacio=si;
        }
        
        if(c->flag_vacio==si)
        {
                return 1;
        }

        if(c->flag_lleno==no)
        {
                for(i=c->i_read ; (i !=c->i_write); i++)
                {
                        i%=MAX;
                        printf("[%d]= %d\n", i, c->buffer[i] );

                }
        }
        else    // si la lista esta llena --> i_read==i_write --> no lo puedo leer de la otra manera
        {
                for(i=c->i_read, j=0; j<MAX ; i++, j++)
                {
                        i%=MAX;
                        printf("[%d]= %d\n", i, c->buffer[i] );         
                }
        }
        return 0;
}       

void eliminar_cola (struct cola *c)
{
        free(c);
}