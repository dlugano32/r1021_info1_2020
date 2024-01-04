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
#include <time.h>

#define TAM 256 

struct usuario
{
        char id[10];
        unsigned int key;
};

int initSocketS(int port, struct sockaddr_in *local);
int initSocketC(int port, char *IP, struct sockaddr_in *server);
void interrupt(int signum);
void cerrar (int signum);