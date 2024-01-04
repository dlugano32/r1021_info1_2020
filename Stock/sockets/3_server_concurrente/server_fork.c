#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0, n_sock=0;      //File descriptor de los sockets
        struct sockaddr_in cliente;     //struct para colocar datos en accept()
        socklen_t l_cliente=sizeof(cliente);    //Size de la struct cliente
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

        s=initSocketS(*(argv+1), &cliente);

        printf("Esperando conexiones...\n");
        while (1)
        {
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

                        /*Seteamos el handler para recibir la señal del proceso hijo pero ignorarla*/
                        signal(SIGCHLD, interrupt);     

                        if( close(n_sock) < 0)
                        {
                                perror("Cerrando el socket");
                                return -1;
                        }
                }
        }

        return 0;
}

