#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0;         // file descriptor del socket
        int n_sock=0;    //file descriptor del canal de datos usada por aceppt
        struct sockaddr_in cliente;       //struct para colocar datos en aceppt()
        socklen_t l_cliente=sizeof(cliente);         //variable para guardar el tamaño de la estructura cliente usada en aceppt()
        char buffer[TAM];       //el buffer usado en read()
        int leidos =0;          //Se guarda la cantidad de caracteres leidos por read()

        if(argc<2)
        {
                printf("Invocar ./server <puerto>\n");
                return -1;

        }

        s=initSocketS(*(argv +1), &cliente);

        while(1)        //loop donde el server va a estar conectado y disponible para transmitir
        {
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
                        // inet_ntoa() function convierte la direccion del host de binario a un string en IPv4 en notacion decimal con la notacion correspondiente
                        // ntohs function convierte un unsigned short integer netshort a network byte order to host byte order.
                        memset(buffer, 0, sizeof(buffer)); //inicializo el buffer en 0

                        while( (leidos=read(n_sock, &buffer, sizeof(buffer))) != 0 ) 
                        {
                                if(leidos < 0)
                                {
                                        perror("En la lectura de datos\n");
                                        return -1;
                                }
                                else
                                {
                                        printf("Mensaje recibido: %s", buffer);
                                        memset(buffer, 0, sizeof(buffer)); //inicializo el buffer en 0
                                }
                        }
                        printf("Conexión terminada\n");
                        close(n_sock);
                }
        }
        return 0;
}