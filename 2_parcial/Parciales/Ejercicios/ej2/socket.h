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

#define TAM 256 

/*        struct sockaddr_in  //para tenerla de ejemplo, ya viene incluida en las librerias
        {
                short sin_family;
                u_short sin_port;
                struct in_addr sin_addr;
                u_long sin_zero[8];
        }
*/

int initSocketS(int port, struct sockaddr_in *local);
int initSocketC(int port, char *IP, struct sockaddr_in *server);
void interrupt1(int signum);

struct data
{
        int nro;
        int votosa;
        int votosb;
        int blancos;
        int anulados;
};

struct ciudad
{
        char nombre[100];
        struct data mesa;
};
