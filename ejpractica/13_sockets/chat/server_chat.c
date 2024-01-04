#include "chat.h"

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
        int flag=0;

        if(argc<2)
        {
                printf("Invocar ./main <puerto>\n");
                return -1;

        }

        /*PASO 1: socket()*/
        s= socket(AF_INET, SOCK_STREAM,0); //creo el socket
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
        /*Se le asignan los parametros de la ip y puerto loca al socket. 
        Además hace una llamada al sistema operativo para avisarle que se creo un socket*/
        if ( bind(s, (struct sockaddr *) &local, sizeof(local)) < 0)
        {
                perror("Asignando direccion");
                return -1;
        }

        /*PASO 3: listen() y accept () */
        /*Ponemos al socket en modo pasivo a la espera de conexiones*/
        listen(s, SOMAXCONN);    //SOMAXCONN es el tamaño maximo la cola de pedidos de conexion

        do        //loop donde el server va a estar conectado y disponible para transmitir
        {
                printf("Esperando conexiones...\n");
                l_cliente=sizeof(cliente);
                /*Funcion bloqueante--> Se queda esperando una conexion. Toma la primer conexion en la cola de pendiente*/
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
                        do
                        {
                                leidos=read(n_sock, &buffer, sizeof(buffer)); //Recibo mensaje
                                if(leidos < 0)
                                {
                                        perror("En la lectura de datos\n");
                                        return -1;
                                }
                                else
                                {       
                                        printf(">>>: %s", buffer);

                                        if( (strcmp(buffer, "chau!\n") == 0) || (strcmp(buffer, "cerrar!\n") == 0) ) //Cuando el cliente manda un mensaje que dice chau! se cierra la comunicacion
                                        {                                                                                                                  //Cuando el cliente manda un mensaje que dice cerrar! se cierra el servidor
                                                printf("Conexión terminada\n");
                                                if (close(n_sock)<0)
                                                {
                                                        perror("Cerrando el socket");
                                                        return -1;
                                                }
                                                flag=1;
                                        }
                                        else
                                        {
                                                memset(buffer, 0, sizeof(buffer)); //inicializo el buffer en 0
                                                printf("<<<: ");
                                                fgets(buffer, TAM, stdin);
                                                if( write (n_sock, buffer, sizeof(buffer) ) < 0) //Respondo al mensaje
                                                {
                                                        perror("Al escribir\n");
                                                        return -1;
                                                }
                                                flag=0;

                                                 if( (strcmp(buffer, "chau!\n") == 0) || (strcmp(buffer, "cerrar!\n") == 0) ) //Cuando el server manda un mensaje que dice chau! se cierra la comunicacion
                                                {                                                                                                                    //Cuando el server manda un mensaje que dice cerrar! se cierra el servidor
                                                        printf("Conexión terminada\n");
                                                        if (close(n_sock)<0)
                                                        {
                                                                perror("Cerrando el socket");
                                                                return -1;
                                                        }
                                                        flag=1;
                                                }
                                                
                                        }       
                                }

                        }while( flag != 1 );
                }

        }while (strcmp(buffer, "cerrar!\n") != 0); //si el mensaje era chau! busca una nueva conexion. Si era cerrar! cierra sale del loop y termina el programa
        return 0;
}