/**
 * \file cliente.c
 * \brief cliente usando socket streams TCP/IP
 * \author Grupo 6
 * \date 26/9/2020
 *  \version 1.1
 */

#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0;        //file descriptor del socket usado en socket()
        struct sockaddr_in server;    //struct para colocar datos en connect()
        char buffer[TAM];
        int i=0;

        if(argc<3)
        {
                printf("Invocar /client <IP o DNS del server> <Puerto>\n");
                return -1;
        }

        for(i=0; i<100; i++)
        {
                s=initSocketC(*(argv +2), *(argv +1), &server);

                if(connect (s, (struct sockaddr*) &server, sizeof(server) ) <0)
                {
                        perror("Al conectar\t");
                        return -1;
                }
                printf("-------------------------------------------------------\n");
                printf("---Conexion N°%d desde %s Puerto: %d \n", i+1, inet_ntoa(server.sin_addr), ntohs(server.sin_port) );

                if( read(s, buffer, TAM) < 0 )
                {
                        perror("Al leer \t");
                        return -1;
                }
                printf("Mensaje recibido -> %s\n", buffer);

                close(s); //cierro el socket
        }

        return 0;
}