/*
 * GCC: gcc -o client sockets_2client.c
 * Ej. Uso: ./client 127.0.0.1 8888
*/

#include "chat.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0;        //file descriptor del socket usado en socket()
        int portn=0;     //Numero de puerto
        struct sockaddr_in server;    //struct para colocar datos en connect()
        struct hostent *sv;       //struct para usar en gethostbyname()
        char buffer[TAM];

        int flag=0;

        if(argc<3)
        {
                printf("./main <IPv4 o DNS> <Puerto>\n");
                return -1;
        }

        /*PASO 1: socket ()*/
        s=socket(AF_INET, SOCK_STREAM, 0);   //creo el socket
        if(s<0)
        {
                perror("No se pudo crear el socket");
                return -1;
        }
        
        sv=gethostbyname(argv[1]); //Obtengo la direccion IP donde está el servidor
        if(sv==NULL)
        {
                perror("No existe el servidor\n");
                return -1;
        }

        /*CONFIGURO LA STRUCT sockaddr_in servidor*/
        portn=atoi(*(argv + 2));        //El numero de puerto se ingresa por argumentos del main
        server.sin_family=AF_INET;      //Dominio AF_INET para comunicaciones de procesos en diferentes maquinas a traves de internet (IPv4)
        server.sin_port=htons(portn);    //Asignar el numero de puerto. Recordar asignar puertos mayores a 1024, que son los que estan reservados
        memcpy(&server.sin_addr.s_addr, sv->h_addr, sv->h_length); //copio datos IP de la estructura sv a la estructura server

        /*PASO 3: connect ()*/
        /*Me conecto con el servidor*/
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