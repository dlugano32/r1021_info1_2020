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
        struct sockaddr_in cliente;     //struct para colocar datos en accept()
        socklen_t l_cliente=sizeof(cliente);    //Size de la struct cliente
        char msj[]={"Hola mundo\n"};
        size_t length=strlen(msj)+1;
        pid_t pid=0;    //Variable para guardar PID's
        int v_pid[MAX], i=0, j=0;

        if(argc<2)
        {
                printf("Invocar ./main <Puerto>\n");
                return -1;

        }

       s=initSocketS(*(argv +1), &cliente);

        printf("Esperando conexiones...\n");

        for(i=0, j=0; i<MAX; i++, j++)
        {
                n_sock = accept(s, (struct sockaddr *) &cliente, &l_cliente);
                if(n_sock < 0)
                {
                        perror("Al aceptar el cliente");
                        return -1;
                }

                printf("-------------------------------------------------------\n");
                printf("---Conexion N°%d desde %s Puerto: %d \n", j+1, inet_ntoa(cliente.sin_addr), ntohs(cliente.sin_port) );

                if( ( pid=fork() ) < 0)         /*Bifurca el programa en proceso padre y procesos hijos*/
                {
                        perror("En el fork\t");
                        return -1;
                }
                else if (pid == 0) /*Proceso HIJO*/
                {
                        if( close(s) < 0 ) //Libero recursos cerrando el socket que se usa para aceptar conexiones
                        {
                                perror("Cerrando socket");
                                return -1;
                        }
                        printf("Proceso hijo PID: %d\n", getpid() );

                        if( write(n_sock, msj, length) < 0)     //Escribo hola mundo al cliente
                        {
                               perror("Al escribir");
                              return -1;
                        }

                        sleep(3);

                        if( close(n_sock) < 0)
                        {
                                perror("Cerrando el socket");
                                return -1;
                        }

                        return 0;
                }
                else
                { /*Proceso PADRE*/

                        v_pid[i]=pid;
                        if( close(n_sock) < 0)
                        {
                                perror("Cerrando el socket");
                                return -1;
                        }
                }

        }

        while (1)
        {
                pid=waitpid(-1, NULL, WNOHANG);

                if(pid != 0)    //Hay un hijo que termino
                {       
                        for(i=0; i<MAX; i++)
                        {
                                if(v_pid[i] == pid)             //busco que hijo es el que termino y cuando lo encuentro lo reemplazo para atender un nuevo cliente
                                {
                                        n_sock = accept(s, (struct sockaddr *) &cliente, &l_cliente);
                                        if(n_sock < 0)
                                        {
                                                perror("Al aceptar el cliente");
                                                return -1;
                                        }
                                        j++;
                                        printf("-------------------------------------------------------\n");
                                         printf("---Conexion N°%d desde %s Puerto: %d \n", j, inet_ntoa(cliente.sin_addr), ntohs(cliente.sin_port) );

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
                                                printf("Proceso hijo PID: %d\n", getpid() );

                                                if( write(n_sock, msj, length) < 0)     //Escribo hola mundo al cliente
                                                {
                                                        perror("Al escribir");
                                                        return -1;
                                                }

                                                sleep(3);

                                                if( close(n_sock) < 0)
                                                {
                                                        perror("Cerrando el socket");
                                                        return -1;
                                                }

                                                return 0;
                                        }
                                        else
                                        { /*Proceso PADRE*/

                                                v_pid[i]=pid;
                                                if( close(n_sock) < 0)
                                                {
                                                        perror("Cerrando el socket");
                                                        return -1;
                                                }
                                        }
                                }
                        }
                }
        }

        return 0;
}

