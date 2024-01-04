/**
 * \file sendto.c
 * \brief  Envia mensajes usando sockets dgram UDP
 * \author Grupo 6
 * \date 30/9/2020
 *  \version 1.1
 */

#include "mylib.h"

int main (int argc, char **argv)
{
        struct sockaddr_in local;             //struct local 
        struct sockaddr_in remote;      //struct remota (a la que vamos a enviar)
        socklen_t rem_len=sizeof(remote);

        int s=0;                        //file descriptor de socket local
        int portn=0;                //numero de puerto
        int recvlen=0, sendlen=0;           //lo devuelto por sendto y recvfrom 
        char buffer[TAM];
        int  i=0;

        if(argc != 3)
        {
                printf("Invocar: ./main <IP> <Puerto>\n");
                return -1;
        }
        
        /**
         * \fn int socket(int domain, int type, int protocol)
         * \brief crea el socket
         * \details Creo un socket de tipo dgram (UDP) en el dominio INET (IPv4)
         * \return Entero. Success: File descriptor del socket. Error: retorna -1
         */
        s=socket(AF_INET, SOCK_DGRAM, 0);
        if(s<0)
        {
                perror("No se pudo crear el socket");
                return -1;
        }

        /*CONFIGURO LA STRUCT local*/
        local.sin_family=AF_INET;       //Dominio AF_INET para comunicaciones de procesos en diferentes maquinas a traves de internet (IPv4)
        local.sin_port=htons(0);    //asignar el numero de puerto. Recordar asignar puertos mayores a 1024, que son los que estan reservados
        local.sin_addr.s_addr=htonl(INADDR_ANY);        //IP de nuestra maquina. Se le agina INADDR_ANY para que sea portable
        memset((void *) &(local.sin_zero), '\0', 8);        // Poner a cero el resto de la estructura

        /**
         * \fn int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
         * \brief se le asignan los parametros de la ip y puerto loca al socket. Además hace una llamada al sistema operativo para avisarle que se creo un socket
         * \return Si es exitosa devuelve un cero. Si hubo un error retorna -1
         */
        if ( bind(s, (struct sockaddr *) &local, sizeof(local)) < 0)     //se asigna una direccion
        {
                perror("Asignando direccion");
                return -1;
        }

        /*CONFIGURO LA STRUCT remote*/  //Struct que contiene los datos del servidor remoto
        portn=atoi(argv[2]);        //El numero de puerto se ingresa por argumentos del main
        remote.sin_family=AF_INET;      //Dominio AF_INET para comunicaciones de procesos en diferentes maquinas a traves de internet (IPv4)
        remote.sin_port=htons(portn);   //asignar el numero de puerto. Recordar asignar puertos mayores a 1024, que son los que estan reservados
        if (inet_aton(argv[1], &remote.sin_addr)==0) //Convierte la direccion del servidor remoto de DNS o IPv4 a binario, guardandolo en la struct
        {
		perror("IP invalida\n");
		return -1;
	}

        for(i=0; i<CANT; i++)
        {
                printf("Enviando mensaje %d a %s: %d\n", i+1, *(argv +1), portn );
                memset(buffer, 0, sizeof(buffer)); //inicializo el buffer en 0
                fgets(buffer, TAM, stdin);
                /**
                 * \fn ssize_t sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen);
                 * \brief Envia un mensaje directo al servidor remoto, ya que tiene todos los datos
                 * \details En flags se pone cero porque no se usa ninguno
                 * \return Success: numero de bytes enviados. Error: -1. Cuando devuelve 0 significa que se cerro la comunicacion.
                 */
                sendlen=sendto(s, buffer, sizeof(buffer), 0, (struct sockaddr *) &remote, rem_len );
                if(sendlen<0)
                {
                        perror("Al enviar datos\n");
                }
                memset(buffer, 0, sizeof(buffer)); //inicializo el buffer en 0
                /**
                 * \fn ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);
                 * \brief Funcion bloqueante, se queda esperando recibir un mensaje de un servidor remoto
                 * \details En flags se pone cero porque no se usa ninguno
                 * \return Success: numero de bytes recibidos. Error: -1. Cuando devuelve 0 significa que se cerro la comunicacion.
                 */
                recvlen=recvfrom(s, buffer, sizeof(buffer), 0,  (struct sockaddr *) &remote, &rem_len);
                if(recvlen<0)
                {
                        perror("Al recivir datos\n");
                        return -1;
                }
                printf("%s\n\n", buffer);
        }

        return 0;
}