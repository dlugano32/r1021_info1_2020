#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define no 0
#define si 1
//PILA -->LIFO= last input first output

struct pila
{
        int buffer[MAX];
        int indice;
        int flag_lleno;
        int flag_vacio;
};

void pila_init( struct pila *);
int push (struct pila * , int);
int pop (struct pila* , int *);
int listar (struct pila*);
void eliminar_pila(struct pila *);

