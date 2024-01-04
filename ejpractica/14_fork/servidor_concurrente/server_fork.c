#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0, n_sock=0, portn=0;
        struct sockaddr_in local;
        struct sockaddr_in cliente;
        socklen_t l_cliente;
        char buffer[TAM];
        int leidos =0, flag=0;
        pid_t pid=0;

        if(argc<2)
        {
                perror("No se proveyo el puerto\n");
                return -1;

        }

        /*PASO 1: socket()*/
        s= socket(PF_INET, SOCK_STREAM,0); 
        if(s<0)
        {
                perror("No se pudo crear el socket");
                return -1;
        }

        /*CONFIGURO LA STRUCT sockaddr_in*/
        portn=atoi(argv[1]);
        local.sin_family=AF_INET;
        local.sin_port=htons(portn);   
        local.sin_addr.s_addr=htonl(INADDR_ANY);
        memset((void *) &(local.sin_zero), '\0', 8);

        /*PASO 2 :bind()*/
        if ( bind(s, (struct sockaddr *) &local, sizeof(local)) < 0)
        {
                perror("Asignando direccion");
                return -1;
        }

        /*PASO 3: listen() y accept () */
        listen(s, SOMAXCONN); 

        printf("Esperando conexiones...\n");
        while (1)
        {
                l_cliente=sizeof(cliente);
                n_sock = accept(s, (struct sockaddr *) &cliente, &l_cliente);   //completa los datos del cliente en el socket de datos n_sock
                if(n_sock < 0)
                {
                        perror("Al aceptar el cliente");
                        return -1;
                }

                printf("---Conexion desde %s Puerto: %d \n", inet_ntoa(cliente.sin_addr), ntohs(cliente.sin_port));

                if( ( pid=fork() ) < 0)
                {
                        perror("En el fork");
                        return -1;
                }
                else if (pid == 0) /*Proceso HIJO*/
                {
                        if( close(s) < 0 ) //Libero recursos
                        {
                                perror("Cerrando socket");
                                return -1;
                        }
                        printf("Proceso padre PPID: %d\n", getppid() );
                        printf("Proceso hijo PID: %d\n", getpid() );

                        while ( flag != 1)
                        {      
                                memset(buffer, 0, sizeof(buffer));
                               if( ( leidos=read(n_sock, buffer, TAM) ) > 0)
                                { 
                                        if( write(n_sock, buffer, leidos) < 0)
                                        {
                                                perror("Al escribir");
                                                return -1;
                                        }
                                        flag=0;
                                }
                                else if (leidos == 0)
                                {
                                        printf("---Saliendo del proceso hijo PID: %d ---\n", getpid());
                                        flag=1;
                                }
                                else
                                {
                                        perror("Al leer");
                                        return -1;
                                }
                                
                        
                        }

                        if( close(n_sock) < 0)
                        {
                                perror("Cerrando el socket");
                                return -1;
                        }

                        return 0;
                }
                else
                { /*Proceso PADRE*/

                        if( close(n_sock) < 0)
                        {
                                perror("Cerrando el socket");
                                return -1;
                        }
                }
        }

        return 0;
}