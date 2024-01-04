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

struct data
{
        char ciudad[32];
        int codpost;
        float sup;
};

int initSocketS(int port, struct sockaddr_in *local);
int initSocketC(int port, char *IP, struct sockaddr_in *server);
void interrupt1 (int signum);
void interrupt2 (int signum);