#include "socket.h"

//Variables globales usadas en la interrupcion
int flag=0;

int main (void)
{
        /*VARIABLES*/
        int s=0, n_sock=0;      //File descriptor de los sockets
        int portn=50000;        //Numero de puerto a usar para establecer la comunicacion
        struct sockaddr_in cliente;     //struct para colocar datos en accept()
        socklen_t l_cliente=sizeof(cliente);    //Size de la struct cliente
        char msg[]={"OK"}, denied[]={"DENEGADO"}, val[]={"VALIDADO"};
        char *str=NULL, *p=NULL, *num=NULL;
        pid_t pid=0;    //Variable para guardar PID's

        FILE *fd_file=NULL;
        struct usuario buffer;
        int length=0, entero[50], i=0;

       srand(time(NULL));

       //Seteo el handler
       signal(SIGINT, cerrar);

        s=initSocketS(portn, &cliente);         //Inicializo el socket

        printf("Esperando conexiones...\n");
        do
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
                       
                        if( write(n_sock, msg, strlen(msg)) <0 )        //Envio el "OK"
                        {
                                printf("Error - Al enviar un mensaje\n");
                                return -1;
                        }

                        if( read(n_sock, &buffer, sizeof(struct usuario)) <0) //Leo la estructura
                        {
                                printf("Error - Al leer el socket\n");
                                return -1;
                        }

                        fd_file=fopen("usuarios.txt", "r");
                        if(fd_file ==NULL)
                        {
                                printf("Error - Al abrir el archivo\n");
                                return -1;
                        }

                        fseek(fd_file, 0, SEEK_END);
                        length=ftell(fd_file);
                        rewind(fd_file);

                        str=(char *) malloc(sizeof(char) * length);
                        if(str ==NULL)
                        {
                                printf("Error al asignar memoria\n");
                        }

                        fread(str, length, 1, fd_file); //Leo el archivo en su totalidad y lo guardo en str
                        
                        p=strstr(str, buffer.id);       //Busco el id en str
                        if(p==NULL)
                        {
                                //Denegado
                                printf("Denegado\n");
                                if( write(n_sock, denied, strlen(denied)) <0 )
                                {
                                        printf("Error - Al enviar un mensaje\n");
                                        return -1;
                                }
                        }
                        else
                        {
                                for(i=0; *(p+i)!= ':'; i++){  } //Adelante el puntero hasta el key
                                p=(p+i) +1;     //El  +1 es para poner el puntero donde empiezan los numeros

                                num=(char *) malloc(sizeof(char));
                                for(i=0; *(p+i)!='\n' && *(p+i)!='\0'; i++)
                                {
                                        *(num + i) = *(p+i);
                                        num=(char*) realloc(num, sizeof(char) *(i+2) );
                                }
                                *(num + i)='\0';

                                if(buffer.key == atoi(num))
                                {
                                        printf("Validado\n");
                                        if( write(n_sock, val, strlen(val)) <0 )
                                        {
                                                printf("Error - Al enviar un mensaje\n");
                                                return -1;
                                        }

                                        for(i=0; i<50; i++)
                                        {
                                                entero[i]=rand();
                                        }

                                        if( write(n_sock, entero, ( sizeof(int) * 50 ) ) <0)
                                        {
                                                printf("Error - Al enviar un mensaje\n");
                                                return -1;
                                        }
                                                
                                }
                                else
                                {
                                        printf("Denegado\n");
                                        if( write(n_sock, denied, strlen(denied)) <0 )
                                        {
                                                printf("Error - Al enviar un mensaje\n");
                                                return -1;
                                        }
                                }
                                
                        }
                        close(n_sock);
                        free(str);
                        free(num);

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
        }while (flag == 0);

        return 0;
}

void cerrar (int signum)
{
        flag=1;
        exit(0);
}       

