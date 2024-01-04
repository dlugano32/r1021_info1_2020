#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define TAM 256

/*
struct sockaddr_in  //para tenerla de ejemplo, ya viene incluida en las librerias
{
        short sin_family;
        u_short sin_port;
        struct in_addr sin_addr;
        u_long sin_zero[8];
}
*/