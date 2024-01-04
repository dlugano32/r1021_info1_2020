#include "my.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0;        //file descriptor del socket usado en socket()
        struct sockaddr_in server;    //struct para colocar datos en connect()
        char buffer[TAM], *str=NULL;
        int portn=50000, length=0;
        FILE *fd_file=NULL;

        if(argc<3)
        {
                printf("Invocar /client <IP o DNS del server> <file.txt>\n");
                return -1;
        }

        s=initSocketC(portn, *(argv +1) , &server);             //inicializo el server

        if(connect (s, (struct sockaddr*) &server, sizeof(server) ) <0)         //Hago la conexion
        {
                perror("Al conectar\t");
                return -1;
        }

        if( read(s, buffer, TAM) < 0)   //Espero el mensaje de confirmacion
        {
                printf("Error - Al leer\n");
                return -1;
        }
        
        if( ( strcmp(buffer, "OK") ) != 0)      //Si el mensaje es "OK" entonces procedo a transferir el archivo
        {
                printf("Conexion NO disponible\n");
                return -1;
        }
        else
        {
                fd_file=fopen(*(argv +2), "r");
                if(fd_file ==NULL)
                {
                        printf("Error - Al leer el archivo");
                        return -1;
                }

                fseek(fd_file, 0, SEEK_END);
                length=ftell(fd_file);          //busco el largo del contenido del archivo
                rewind(fd_file);

                str=(char *) malloc(sizeof(char) * length);          //reservo memoria para leer el archivo
                if(str==NULL)
                {
                        printf("Error - Al asignar memoria\n");
                        return -1;
                }

                fread(str, length, 1, fd_file);               //Leo el archivo
                if( write(s, str, length) <0)                  //Escribo la informacion leida en el socket
                {
                        printf("Error - Al escribir en el socket\n"); 
                        return -1;
                }
                else
                {
                        printf("Conexión exitosa, archivo enviado\n");
                }
        }
        

        fclose(fd_file); //cierro el file
        close(s); //cierro el socket
        return 0;
}