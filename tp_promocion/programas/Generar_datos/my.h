#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define CANT 8640       //cantidad de 10 segundos en un dia
#define ZONAS 10

//Zona;AAAAMMDD;HHMMSS;VOLT

struct medicion         //Estructura necesaria para guardar los datos y luego imprimirlas en el archivo. No la pide en el tp pero a mi me es útil.
{
        int zona; 
        int volt; 
};
