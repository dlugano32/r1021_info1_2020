#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0;         // file descriptor del socket
        int n_sock=0;    //file descriptor del canal de datos usada por aceppt
        struct sockaddr_in cliente;       //struct para colocar datos en aceppt()
        socklen_t l_cliente=sizeof(cliente);         //variable para guardar el tamaño de la estructura cliente usada en aceppt()
        char *buffer=NULL;       //el buffer usado en read()
        long int length=0;

        if(argc<2)
        {
                printf("Invocar ./server <puerto>\n");
                return -1;

        }

        s=initSocketS(*(argv +1), &cliente);

        printf("Esperando conexiones...\n");

        n_sock = accept(s, (struct sockaddr *) &cliente, &l_cliente);  
        if(n_sock < 0)
        {
                perror("Al aceptar el cliente");
                return -1;
        }
        else
        {
                printf("Conexion establecida con %s: %d\n", inet_ntoa(cliente.sin_addr), ntohs(cliente.sin_port));

                if( read(n_sock, &length, sizeof(long int) ) <0 )
                {
                        perror("En la lectura de datos\n");
                        return -1;
                }
                
                buffer=(char *) malloc( length * sizeof(char) );
                if(buffer ==NULL )
                {
                        perror("Error - Al pedir memoria\t");
                        exit(-1);
                }

                if (read(n_sock, &buffer, length ) <0) 
                {
                        perror("En la lectura de datos\n");
                        return -1;

                }

                printf("Mensaje recibido:\n%s", buffer);
                printf("Conexión terminada\n");

                free(buffer);
                close(n_sock);
        }

        return 0;
}