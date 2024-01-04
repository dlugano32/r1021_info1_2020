#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0;
        int portn=0;
        struct sockaddr_in server;
        struct hostent *sv;
        char buffer[TAM];

        int flag=0;

        if(argc<3)
        {
                perror("Datos de ingreso");
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
        portn=atoi(*(argv + 2));
        server.sin_family=AF_INET; 
        server.sin_port=htons(portn);
        memcpy(&server.sin_addr.s_addr, sv->h_addr, sv->h_length);

        /*PASO 3: connect ()*/
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
                
                        if( (strcmp (buffer, "cerrar!\n") ==0 ) || (strcmp(buffer, "chau!\n")==0) )
                        {
                                if(close(s) < 0) //cierro el socket
                                {
                                        perror("Cerrando");
                                        return -1;
                                }
                                flag=1;
                        }
                        else
                        {       memset(buffer, 0, sizeof(buffer));
                                if( read (s, buffer, sizeof(buffer) ) < 0)  
                                {
                                        perror("Al leer\n");
                                        return -1;
                                }
                                printf(">>>: %s", buffer);
                                flag=0;
                        }
                }while(flag!=1);
        }
        return 0;
}
