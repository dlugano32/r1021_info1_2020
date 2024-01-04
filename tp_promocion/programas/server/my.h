#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>


#define TAM 190080
#define CANT 8640       //cantidad de 10 segundos en un dia
#define BARRAS 24
#define width 720       //Resolucion en pixeles 720x480
#define height 480 
#define ref_y 9


struct fecha 
{
        int anio;
        char dia,mes;
        char hora,min,seg;
};

struct medicion 
{
        char area; // Area de la ciudad medida
        struct fecha f; // Fecha y hora de la medición
        int volt; // Valor medido (sin decimales)
};

struct anomalia
{
        char zona;
        int anio;
        char dia, mes;
        char hora_in, hora_fin;
        int T_max, T_min;
};

int initSocketS(int port, struct sockaddr_in *local);
int save_data( struct medicion **vec, FILE *fp );
int fill_struct_med(struct medicion *data, char *str);
void detectar_fluctuaciones(struct medicion **vec, int cant,  FILE *fp);
void fill_struct_anom(struct anomalia *registro, struct medicion *vec, int i, int T_max, int T_min);
void prom_tension(float *prom, struct medicion **vec, int cant);
void init_allegro(void);
void grafico (float *data, int zona);
void shutdown_allegro(void);
