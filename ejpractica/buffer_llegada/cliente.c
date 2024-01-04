#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0;        //file descriptor del socket usado en socket()
        struct sockaddr_in server;    //struct para colocar datos en connect()
        char buffer[256];

        if(argc<3)
        {
                printf("Invocar /client <IP o DNS del server> <Puerto>\n");
                return -1;
        }

        s=initSocketC(*(argv + 2), *(argv+1), &server);

        if(connect (s, (struct sockaddr*) &server, sizeof(server) ) <0)
        {
                perror("Al conectar\n");
                return -1;
        }

        /*PASO 3: write()*/
        /**
         * \fn ssize_t write(int fd, void *buf, size_t count)
         * \brief Escribo al server
         * \return Success: cantidad de bytes escritos. Error: -1
         */
        printf("Escriba su mensaje: \n");

        memset((void *) buffer, '\0', TAM);
        fgets(buffer,TAM,stdin);
        if( write (s, buffer, TAM ) < 0)
        {
                perror("Al escribir\n");
                return -1;
        }

        /*PASO 4: close ()*/
        /**
         * \fn int close(int fd)
         * \brief Cierra el socket. La conexion y la comunicacion se da por terminada
         * \return Success: 0    Error: -1
        */
        close(s); //cierro el socket
        return 0;
}