#include "pila.h"

void pila_init( struct pila *pila )
{
        pila->indice=0;
        pila->flag_lleno=no;
        pila->flag_vacio=si;
}

int push (struct pila *pila, int dato)     //Escribo en la pila
{
        if(pila->indice>=MAX)      //pila llena
        {
                pila->flag_lleno=si;
                return 1;
        }
        pila->buffer[pila->indice]=dato;
        pila->indice++;
        pila->flag_vacio=no; //Como ingrese un dato la pila no esta mas vacia en caso de que lo estuviera

        return 0;
}

int pop (struct pila *pila, int *dato)
{
        pila->indice--;
        if(pila->indice < 0)       //pila vacia
        {
                pila->flag_vacio=si;
                pila->indice=0;
                return 1;
        }
        *dato=pila->buffer[pila->indice];
        pila->flag_lleno=no;    //si la pila estaba llena ahora no.

        return 0;
}

int listar (struct pila * pila)
{
        int i=0;

        pila->indice--;
        if(pila->indice < 0)       //Compruebo si la pila esta vacia
        {
                pila->indice=0;
                pila->flag_vacio=si;
                return 1;
        }
        pila->indice++;

        for(i= (pila->indice -1); i>=0 ; i--)             //Le resto uno porque siempre el indice esta en la posicion de escribir y no en la de leer
        {
                printf("[%d]= %d\n", i, pila->buffer[i]);
        }

        return 0;
}

void eliminar_pila (struct pila *pila)
{
        free(pila);
}