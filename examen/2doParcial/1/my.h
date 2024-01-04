#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include<sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define TAM 1024
#define MAX 20
#define no 0
#define si 1

struct mem
{
        int MemFree;
        int MemAvailable;
        int SwapFree;
};

//Cola
struct cola
{
        struct mem buffer[MAX];
        int i_read;
        int i_write;
        int flag_lleno;
        int flag_vacio;
};

void cola_init( struct cola *);
void push (struct cola * , struct mem);
