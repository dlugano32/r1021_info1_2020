#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
float temp;
char fecha[9];
char hora[9];
};

void file_out(char **, char*, const char*);