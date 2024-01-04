#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct mediciones
{
       int id;
       int time;
       float valor;
       char unidad[5];
};

//FUNCIONES
void save_struct(FILE *, struct mediciones **, int);
void ordenar_struct(struct mediciones **, int);
void imprimir_struct(struct mediciones **, int);
void file_out(char **, char*, const char*);
void archivo_salida_dat(FILE *, struct mediciones **, int);
void archivo_salida_txt(FILE *, struct mediciones **, int);

