#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0;        //file descriptor del socket usado en socket()
        struct sockaddr_in server;    //struct para colocar datos en connect()
        char buffer[TAM];

        int flag=0;

        if(argc<3)
        {
                printf("./main <IPv4 o DNS> <Puerto>\n");
                return -1;
        }

        s=initSocketC(*(argv +2), *(argv +1), &server);

        if(connect (s, (struct sockaddr*) &server, sizeof(server) ) <0)
        {
                perror("Al conectar\n");
                return -1;
        }
        else
        {
                do
                {
                        memset(buffer, 0, sizeof(buffer));
                        printf("<<<: ");
                        fgets(buffer,TAM,stdin);
                        if( write (s, buffer, sizeof(buffer) ) < 0)  
                        {
                                perror("Al escribir\n");
                                return -1;
                        }
                
                        if( (strcmp (buffer, "cerrar!\n") ==0 ) || (strcmp(buffer, "chau!\n")==0) )     //Si mando el mensaje cerrar! o chau! cierra el socket de comunicacion
                        {
                                if(close(s) < 0) //cierro el socket
                                {
                                        perror("Cerrando");
                                        return -1;
                                }
                                flag=1;
                        }
                        else
                        {       
                                flag=0;
                                memset(buffer, 0, sizeof(buffer));
                                if( read (s, buffer, sizeof(buffer) ) < 0)  
                                {
                                        perror("Al leer\n");
                                        return -1;
                                }
                                printf(">>>: %s", buffer);
                                
                                if( (strcmp (buffer, "cerrar!\n") ==0 ) || (strcmp(buffer, "chau!\n")==0) )     //Si mando el mensaje cerrar! o chau! cierra el socket de comunicacion
                                {
                                        if(close(s) < 0) //cierro el socket
                                        {
                                                perror("Cerrando");
                                                return -1;
                                        }
                                        flag=1;
                                }
                        }
                }while(flag!=1);
        }
        return 0;
}