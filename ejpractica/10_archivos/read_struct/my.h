#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Poner aca la struct a leer*/
struct mediciones
{
       int id;
       int time;
       float valor;
       char unidad[5];
};

void save_struct(FILE*, struct mediciones**, int);