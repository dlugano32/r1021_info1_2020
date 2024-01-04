#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define CANT_ELEMENTOS 5
#define MAX_SEGS 10
#define no 0
#define si 1
#define SEPARADOR puts("--------------------------------");
#define COLA_LLENA 2

typedef struct Nodo tipo_elemento;

struct Nodo {

    float temp;
    char fecha[8];
    char hora[8];

};

typedef struct {
	
	tipo_elemento* BUFFER;
	int escribir;
	int leer;
	int flag_vacio;
	int flag_lleno;
	int tam_buffer;	
	}fifo_circular;

fifo_circular *crear_fifo_circular (int tam_lista);
int cargar_elemento_fifo_circular (fifo_circular *lista, tipo_elemento elemento);
int sacar_elemento_fifo_circular (fifo_circular *lista, tipo_elemento *elemento);
int mostrar_elementos_fifo_circular (fifo_circular *lista);
void eliminar_fifo_circular (fifo_circular *lista);