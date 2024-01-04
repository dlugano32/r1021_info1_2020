#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0;        //file descriptor del socket usado en socket()
        struct sockaddr_in server;    //struct para colocar datos en connect()
        char buffer[TAM];
        int portn=50000, num[50];
        struct usuario usr;

        if(argc != 2)
        {
                printf("Invocar /client <IP o DNS del server>\n");
                return -1;
        }

        printf("Ingrese el identificador de usuario y contraseña\nUsuario [10]:\t");
        scanf("%s", usr.id);
        printf("Password\t");
        scanf("%d", &usr.key);

       s=initSocketC(portn, *(argv +1), &server);
        
        if(connect (s, (struct sockaddr*) &server, sizeof(server) ) <0)
        {
                perror("Al conectar\n");
                return -1;
        }
        memset(buffer, 0, sizeof(buffer)); //inicializo el buffer en 0
        if(read (s, buffer, TAM ) < 0 )
        {
                printf("Error - Al leer el socket");
                return -1;
        }

        if( strcmp(buffer, "OK") != 0 )
        {
                printf("Comunicación NO disponible");
                return -1;
        }
        else
        {
                if( write(s, &usr, sizeof(struct usuario) ) < 0)                //Envio el usuario y la contraseña
                {
                        printf("Error - Al escribir el socket\n");
                        return -1;
                }
                
                memset(buffer, 0, sizeof(buffer)); //inicializo el buffer en 0
                if( read(s, buffer, TAM) <0)
                {
                        printf("Error - Al leer el socket\n");
                        return -1;
                }

                if( strcmp(buffer, "VALIDADO") == 0 )
                {
                        printf("Validado\n");
                        if( read(s, num, ( sizeof(int) *50 ) ) <0 )
                        {
                                printf("Error - Al leer el socket\n");
                                return -1;
                        }
                }
                else
                {
                        printf("Denegado\nCombinación usuario/contraseña incorrecta\n");
                }

        }

        close(s); //cierro el socket
        return 0;
}