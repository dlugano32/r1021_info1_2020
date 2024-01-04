/**
 * \file server_fork.c
 * \brief servidor concurrente usando socket streams TCP/IP
 * \author Grupo 6
 * \date 26/9/2020
 *  \version 1.1
 */

#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0, n_sock=0;      //File descriptor de los sockets
        int portn=0;    //Numero de puerto
        struct sockaddr_in local;       //struct para colocar datos en bind()
        struct sockaddr_in cliente;     //struct para colocar datos en accept()
        socklen_t l_cliente;    //Size de la struct cliente
        char buffer[TAM];       //buffer que se usa en read() y write()      
        char msj[]={"Hola mundo\n"};
        size_t length=strlen(msj)+1;
        int leidos =0, flag=0;
        pid_t pid=0;    //Variable para guardar PID's

        if(argc<2)
        {
                printf("Invocar ./main <Puerto>\n");
                return -1;

        }

        /*PASO 1: socket()*/
        /*Creo el socket para recibir conexiones */
        s= socket(AF_INET, SOCK_STREAM,0); 
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
                n_sock = accept(s, (struct sockaddr *) &cliente, &l_cliente);
                if(n_sock < 0)
                {
                        perror("Al aceptar el cliente");
                        return -1;
                }

                printf("---Conexion desde %s Puerto: %d \n", inet_ntoa(cliente.sin_addr), ntohs(cliente.sin_port) );

                if( ( pid=fork() ) < 0)         /*Bifurca el programa en proceso padre y procesos hijos*/
                {
                        perror("En el fork");
                        return -1;
                }
                else if (pid == 0) /*Proceso HIJO*/
                {
                        if( close(s) < 0 ) //Libero recursos cerrando el socket que se usa para aceptar conexiones
                        {
                                perror("Cerrando socket");
                                return -1;
                        }
                        printf("Proceso padre PPID: %d\n", getppid() );
                        printf("Proceso hijo PID: %d\n", getpid() );

                        if( write(n_sock, msj, length) < 0)     //Escribo hola mundo al cliente
                        {
                               perror("Al escribir");
                              return -1;
                        }

                        while ( flag != 1)
                        {      
                                memset(buffer, 0, sizeof(buffer));      //reset buffer
                               if( ( leidos=read(n_sock, buffer, TAM) ) > 0)    //Si no hubo error al leer escribo la respuesta
                                { 
                                        printf("-Mensaje del cliente %s\tPort:%d\n>>>%s\n", inet_ntoa(cliente.sin_addr), ntohs(cliente.sin_port), buffer);
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