#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 256

struct listado
{
        char **str;
        int cant;
};
struct listado function ( char *archStr);