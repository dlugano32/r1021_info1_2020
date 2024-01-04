#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0;         // file descriptor del socket
        int n_sock=0;    //file descriptor del canal de datos usada por aceppt
        struct sockaddr_in cliente;       //struct para colocar datos en aceppt()
        socklen_t l_cliente=sizeof(cliente);         //variable para guardar el tamaño de la estructura cliente usada en aceppt()
        char buffer[TAM], *str=NULL;
        int leidos =0, cant=0;

        str=(char *) malloc(sizeof(char));
        
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
                        memset(buffer, 0, sizeof(buffer)); //inicializo el buffer en 0

                        while( (leidos=read(n_sock, &buffer, 50)) != 0 ) 
                        {
                                if(leidos < 0)
                                {
                                        perror("En la lectura de datos\n");
                                        return -1;
                                }
                                else
                                {
                                        str=(char *)realloc(str, sizeof(char) * (cant + leidos));

                                        if(cant==0)
                                        {
                                                strcpy(str, buffer);
                                        }
                                        else
                                        {       
                                                strcat(str, buffer);
                                        }
                                        cant= cant + leidos;
                                }
                        }
                        printf("Conexión terminada\n");
                        printf("El str recibido es:\t%s\n", str);
                        free(str);
                        close(n_sock);
                }
        }

        
        
        return 0;
}