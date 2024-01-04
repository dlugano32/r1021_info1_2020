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
        int portn=0;     //Numero de puerto
        struct sockaddr_in server;    //struct para colocar datos en connect()
        struct hostent *sv;       //struct para usar en gethostbyname()
        char buffer[TAM];

        if(argc<3)
        {
                printf("Invocar /client <IP o DNS del server> <Puerto>\n");
                return -1;
        }

        /*PASO 1: socket ()*/
        /**
         * \fn int socket(int domain, int type, int protocol)
         * \brief crea el socket
         * \details Creo un socket de tipo stream (TCP) en el dominio INET (IPv4)
         * \return Entero. Success: File descriptor del socket. Error: retorna -1
         */
        s=socket(AF_INET, SOCK_STREAM, 0);
        if(s<0)
        {
                perror("No se pudo crear el socket");
                return -1;
        }
        
        sv=gethostbyname(argv[1]);      //Obtengo la direccion IP donde está el servidor
        if(sv==NULL)
        {
                perror("No existe el servidor\n");
                return -1;
        }

        /*CONFIGURO LA STRUCT sockaddr_in servidor*/
        portn=atoi(*(argv + 2));                //El numero de puerto se ingresa por argumentos del main
        server.sin_family=AF_INET;      // Dominio AF_INET para comunicaciones de procesos en diferentes maquinas a traves de internet (IPv4)
        server.sin_port=htons(portn);    //Asignar el numero de puerto. Recordar asignar puertos mayores a 1024, que son los que estan reservados
        memcpy(&server.sin_addr.s_addr, sv->h_addr, sv->h_length);      //copio datos IP de la estructura sv a la estructura server

        /*PASO 2: connect ()*/
        /**
         * \fn int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
         * \brief Me conecto con el servidor
         * \return Success: 0   Error: -1
         */
        
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
        /*PASO 4: close ()*/
        /**
         * \fn int close(int fd)
         * \brief Cierra el socket. La conexion y la comunicacion se da por terminada
         * \return Success: 0    Error: -1
        */
        close(s); //cierro el socket
        return 0;
}