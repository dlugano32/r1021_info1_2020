#include "socket.h"

int main (int argc, char **argv)
{
        int s=0;        //file descriptor del socket usado en socket()
        struct sockaddr_in server;    //struct para colocar datos en connect()
        struct ciudad voto;
        int portn=50000;
        char buffer[TAM];

        if(argc != 4)
        {
                printf("./client <DNS o ip> <Ciudad> <N° Mesa>\n");
        }

        strcpy(voto.nombre, *(argv+2) );
        voto.mesa.nro=atoi(*(argv + 3) );
        printf("Ingrese la cantidad de Votos del candidato A\n");
        scanf("%d", &voto.mesa.votosa);
        printf("Ingrese la cantidad de Votos del candidato B\n");
        scanf("%d", &voto.mesa.votosb);
        printf("Ingrese la cantidad de Votos en blanco\n");
        scanf("%d", &voto.mesa.blancos);
        printf("Ingrese la cantidad de votos anulados\n");
        scanf("%d", &voto.mesa.anulados);

        s=initSocketC(portn, *(argv +1), &server);
       if(connect (s, (struct sockaddr*) &server, sizeof(server) ) <0)
        {
                perror("Al conectar\n");
                return -1;
        }

        if( read(s, buffer, TAM) < 0)
        {
                printf("Error - Al leer el socket\n");
                return -1;
        }

        if( strcmp(buffer, "OK") != 0)
        {
                printf("Conexion NO disponible\n");
        }
        else
        {
                if( write(s, &voto, sizeof(struct ciudad) )<0 )
                {
                        printf("Error - Al escribir en el socket\n");
                        return -1;
                }       
                else
                {
                        printf("Conexión exitosa. Archivo enviado\n");
                }
        }
        
        close(s);
        return 0;
}