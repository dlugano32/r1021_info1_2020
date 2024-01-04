#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TAM 256
//#define HOST "127.0.0.1"
//#define PORT 50000

int initSocketC( char *, int , struct sockaddr_in *);
char * my_itoa (int);