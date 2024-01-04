#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_S 31

struct datos {
long legajo;
char apellido[31];
char nombre[31];
};

void carga(struct datos *);
int fin(struct datos *);
void ordenar_apellido(struct datos **, int);

