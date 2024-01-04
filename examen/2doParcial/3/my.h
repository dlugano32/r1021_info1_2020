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

int initSocketC(int port, char *IP, struct sockaddr_in *server);