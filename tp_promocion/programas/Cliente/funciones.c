#include "my.h"

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