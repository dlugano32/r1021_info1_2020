/**
 * \file servidor.c
 * \brief servidor usando socket streams TCP/IP
 * \author Grupo 6
 * \date 26/9/2020
 *  \version 1.1
 */

#include "socket.h"

int main (int argc, char **argv)
{
        /*VARIABLES*/
        int s=0;         // file descriptor del socket
        int n_sock=0;    //file descriptor del canal de datos usada por aceppt
        int portn=0;     //Numero de puerto
        struct sockaddr_in local;     //struct para colocar datos en bind()
        struct sockaddr_in cliente;       //struct para colocar datos en aceppt()
        socklen_t l_cliente;           //variable para guardar el tamaño de la estructura cliente usada en aceppt()
        char buffer[TAM];       //el buffer usado en read()
        int leidos =0;          //Se guarda la cantidad de caracteres leidos por read()

        if(argc<2)
        {
                printf("Invocar ./server <puerto>\n");
                return -1;

        }

        /*PASO 1: socket()*/
        /**
         * \fn int socket(int domain, int type, int protocol)
         * \brief crea el socket
         * \details Creo un socket de tipo stream (TCP) en el dominio INET (IPv4)
         * \return Entero. Success: File descriptor del socket. Error: retorna -1
         */
        s= socket(AF_INET, SOCK_STREAM,0);
        if(s<0)
        {
                perror("No se pudo crear el socket");
                return -1;
        }

        /*CONFIGURO LA STRUCT sockaddr_in*/
        portn=atoi(argv[1]);        //El numero de puerto se ingresa por argumentos del main
        local.sin_family=AF_INET;       //Dominio AF_INET para comunicaciones de procesos en diferentes maquinas a traves de internet (IPv4)
        local.sin_port=htons(portn);    //Asignar el numero de puerto. Recordar asignar puertos mayores a 1024, que son los que estan reservados
        local.sin_addr.s_addr=htonl(INADDR_ANY);        //IP de nuestra maquina. Se le agina INADDR_ANY para que sea portable
        memset((void *) &(local.sin_zero), '\0', 8);        // Poner a cero el resto de la estructura

        /*PASO 2 :bind()*/
        /**
         * \fn int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
         * \brief se le asignan los parametros de la ip y puerto loca al socket. Además hace una llamada al sistema operativo para avisarle que se creo un socket
         * \return Si es exitosa devuelve un cero. Si hubo un error retorna -1
         */
        if ( bind(s, (struct sockaddr *) &local, sizeof(local)) < 0)   
        {
                perror("Asignando direccion");
                return -1;
        }

        /*PASO 3: listen() y accept () */    
        /**
         * \fn int listen(int sockfd, int backlog);
         * \brief Pone al socket en modo pasivo a la espera de conexiones
         * \details backlog: es el tamaño de la cola de clientes en espera. SOMAXCONN es el tamaño maximo que permite el SO
         * \return Success : 0   Error: -1
         */
        listen(s, SOMAXCONN);

        while(1)        //loop donde el server va a estar conectado y disponible para transmitir
        {
                printf("Esperando conexiones...\n");
                l_cliente=sizeof(cliente);
                /**
                 * \fn int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
                 * \brief Funcion bloqueante--> Se queda esperando una conexion. Toma la primer conexion en la cola de pendientes
                 * \details Crea un socket de comunicacion con los datos del cliente. El socket se va a usar para la comunicacion
                 * \return Success: File descriptor del socket de comunicacion. Error : -1
                 */
                n_sock = accept(s, (struct sockaddr *) &cliente, &l_cliente);  
                if(n_sock < 0)
                {
                        perror("Al aceptar el cliente");
                        return -1;

                }
                else
                {
                        printf("Conexion establecida con %s: %d\n", inet_ntoa(cliente.sin_addr), ntohs(cliente.sin_port));
                        // inet_ntoa() function convierte la direccion del host de binario a un string en IPv4 en notacion decimal con la notacion correspondiente
                        // ntohs function convierte un unsigned short integer netshort a network byte order to host byte order.
                        memset(buffer, 0, sizeof(buffer)); //inicializo el buffer en 0

                        /*PASO 4: read() write() --> comunicacion*/
                        /**
                         * \fn ssize_t read(int fd, void *buf, size_t count)
                         * \brief Escucho lo que me manda el cliente
                         * \return Success: cantidad de bytes leidos. Error: -1
                         */
                        while( (leidos=read(n_sock, &buffer, sizeof(buffer))) != 0 ) 
                        {
                                if(leidos < 0)
                                {
                                        perror("En la lectura de datos\n");
                                        return -1;
                                }
                                else
                                {
                                        printf("Mensaje recibido: %s", buffer);
                                        memset(buffer, 0, sizeof(buffer)); //inicializo el buffer en 0
                                }
                        }
                        /*PASO 5 close()*/
                        printf("Conexión terminada\n");
                        /**
                         * \fn int close(int fd)
                         * \brief Cierra el socket. La conexion y la comunicacion se da por terminada
                         * \return Success: 0    Error: -1
                         */
                        close(n_sock);
                }
        }
        return 0;
}