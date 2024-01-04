#include "socket.h"

int initSocketS(int port, struct sockaddr_in *local)
{
        int s=0;

        /*PASO 1: socket()*/
        s= socket(AF_INET, SOCK_STREAM,0); 
        if(s<0)
        {
                perror("No se pudo crear el socket");
                exit(1);
        }

        /*CONFIGURO LA STRUCT sockaddr_in*/
        local->sin_family=AF_INET;
        local->sin_port=htons(port);   
        local->sin_addr.s_addr=htonl(INADDR_ANY);
        memset((void *) &(local->sin_zero), '\0', 8);

        /*PASO 2 :bind()*/
        if ( bind(s, (struct sockaddr *) local, sizeof( *local )) < 0)
        {
                perror("Asignando direccion");
                exit(1);
        }

        /*PASO 3: listen() y accept () */
        listen(s, SOMAXCONN);

        return s;
}

int initSocketC(int port, char *IP, struct sockaddr_in *server)
{
        int s=0;
        struct hostent *sv;       //struct para usar en gethostbyname()

        s=socket(AF_INET, SOCK_STREAM, 0);
        if(s<0)
        {
                perror("No se pudo crear el socket");
                return -1;
        }
        
        sv=gethostbyname(IP);      //Obtengo la direccion IP donde está el servidor
        if(sv==NULL)
        {
                perror("No existe el servidor\n");
                return -1;
        }

        /*CONFIGURO LA STRUCT sockaddr_in servidor*/
        server->sin_family=AF_INET;      // Dominio AF_INET para comunicaciones de procesos en diferentes maquinas a traves de internet (IPv4)
        server->sin_port=htons(port);    //Asignar el numero de puerto. Recordar asignar puertos mayores a 1024, que son los que estan reservados
        memcpy(&server->sin_addr.s_addr, sv->h_addr, sv->h_length);      //copio datos IP de la estructura sv a la estructura server

        return s;
}

