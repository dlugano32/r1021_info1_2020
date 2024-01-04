#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 256

struct alumno
{
       int legajo;
       char *nombre, *apellido;
       
};

void carga(struct alumno *);
void ordenar_apellido(struct alumno **, int);