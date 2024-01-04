#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define TAM 256

struct conf
{
        int port;
        int backLog;
        char archStr[1024];
};

struct listado
{
        char **str;
        int cant;
};

struct conf load_conf( char *);
int initSocketS(struct conf *, struct sockaddr_in *);
void threadTransfer(int , char ** , int);
struct listado listar ( char *);
void interrupt(int);
