#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0;        //file descriptor del socket usado en socket()
        struct sockaddr_in server;    //struct para colocar datos en connect()
        char buffer[TAM];

        if(argc<3)
        {
                printf("Invocar /client <IP o DNS del server> <Puerto>\n");
                return -1;
        }

       s=initSocketC(*(argv +2), *(argv +1), &server);
        
        if(connect (s, (struct sockaddr*) &server, sizeof(server) ) <0)
        {
                perror("Al conectar\n");
                return -1;
        }

        if(read (s, buffer, sizeof(buffer) ) < 0 )
        {
                perror("Al escribir\t");
                return -1;
        }
        printf("-Mensaje del server %s\tPort:%d\n>>>%s\n", inet_ntoa(server.sin_addr), ntohs(server.sin_port), buffer);

        printf("Escriba su mensaje: \n");
        do
        {
                memset((void *) buffer, '\0', TAM);
                printf("<<<");
                fgets(buffer,TAM,stdin);
                if( write (s, buffer, sizeof(buffer) ) < 0)
                {
                        perror("Al escribir\n");
                        return -1;
                }
                
        }while(strcmp("cerrar!\n", buffer) != 0);

        close(s); //cierro el socket
        return 0;
}