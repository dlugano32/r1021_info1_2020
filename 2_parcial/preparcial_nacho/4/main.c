/* 4) Crear el programa que lea la configuración (usando la función creada en 1) desde un archivo pasado como primer argumento del main. 
Luego llamar a la función initSocketS() (ya creada) que toma el port (provisto por la configuración) inicializando el socket a utilizar en este servidor.
 La función initSocketS() devuelve un entero que es el número de socket listo para ser utilizado en un accept(). Esta función se deberá quedar esperando 
 hasta backLog conexiones. Cada vez que reciba una nueva conexión deberá crear un thread para manejar la transferencia. 
 Realice además dentro del main todos los pasos que considere necesarios para finalizar el programa liberando todos los recursos utilizados.
 */
#include "my.h"

int main (int argc, char **argv)
{
        struct conf dev;
        struct listado dev2;
        int fd_sock=0;          //File descriptor del socket
        int fd_com=0;           //FIle descriptor del socket de comunicacion
        struct sockaddr_in local;       //struct para colocar datos en bind()
        struct sockaddr_in cliente;     //struct para colocar datos en accept()
        socklen_t l_cliente=sizeof(cliente);    //Size de la struct cliente
        int pid=0, i=0;

        if( argc != 2)
        {
                printf("Invocar como ./main <archivo.txt>\n");
                return 1;
        }
        
        dev=load_conf(argv[1]);
        fd_sock=initSocketS(&dev, &local);

        printf("Esperando conexiones...\n");
        for(i=0; i<dev.backLog; i++)
        {
                fd_com= accept(fd_sock, (struct sockaddr *) &cliente, &l_cliente);                
                if(fd_com < 0)
                {
                        printf("Error - Al aceptar conexion\n");
                        exit(1);
                }

                /*Hago fork*/
                pid=fork(); 
                if(pid<0)
                {
                        printf("Error - En el fork\n");
                        exit(1);
                }

                if(pid==0)       /*Proceso hijo*/
                {
                        if( close(fd_sock) <0 )         //cierro el socket del server
                        {
                                printf("Error - Al cerrar el socket\n");
                                exit(1);
                        }

                        dev2=listar(dev.archStr);       //LLamo a la funcion que me devuelve la lista de los archivos

                        threadTransfer(fd_com, dev2.str, dev2.cant);    //funcion usada para transferir

                        for(i=0; i<dev2.cant; i++)
                        {
                                free(dev2.str[i]);
                        }
                        free(dev2.str);

                        if( close(fd_com) <0 )
                        {
                                printf("Error - Al cerrar el socket\n");
                                exit(1);
                        }

                        return 0;
                }
                else    /*Proceso padre*/
                {
                        /*Seteamos el handler para recibir la señal del proceso hijo pero ignorarla*/
                        signal(SIGCHLD, interrupt);

                        if( close(fd_com) < 0 )
                        {
                                printf("Error - Al cerrar el socket\n");
                                exit(1);
                        }
                }
        }

        return 0;
}