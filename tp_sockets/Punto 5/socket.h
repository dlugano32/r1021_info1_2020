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
#define MAX 10

int initSocketS(char *, struct sockaddr_in *);
int initSocketC(char *, char *, struct sockaddr_in *);