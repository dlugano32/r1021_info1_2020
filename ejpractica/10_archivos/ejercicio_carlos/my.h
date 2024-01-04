#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef unsigned char uchar;

struct mediciones
{
       int id;
       int time;
       float valor;
       char unidad[5];
};

typedef struct //el b0 es el menos significativo
{
       uchar b0:1;
       uchar b1:1;
       uchar b2:1;
       uchar b3:1;
       uchar b4:1;
       uchar b5:1;
       uchar b6:1;
       uchar b7:1;
}bin;

union byte
{
       uchar x;
       bin b;
};

//FUNCIONES
void save_struct(FILE*, struct mediciones**, int);
void ord_unidad (struct mediciones **, int);
void ord_time (struct mediciones **, int);
void imprimir_struct(struct mediciones **, int);
void file_out(char **, char*, const char*);
void archivo_salida_dat(FILE *, struct mediciones **, int);
void archivo_salida_txt(FILE *, struct mediciones **, int);
