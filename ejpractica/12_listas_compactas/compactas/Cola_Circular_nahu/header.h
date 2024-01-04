#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CANT_ELEMENTOS 5
#define no 0
#define si 1
#define SEPARADOR puts("--------------------------------");

typedef float tipo_elemento;

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