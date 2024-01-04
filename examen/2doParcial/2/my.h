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

#define CANT 288

struct mem
{
        int time_stap;
        float MemFree;
        float MemAvailable;
        float SwapFree;
};

void file_out(char ** archivo, char*str, char *fin);