/*      5) Crear un programa cliente que llame a la función initSocketC() que no toma nada (pide la IP y puerto sola) y devuelve un socket 
ya abierto que se deberá utilizar para recibir datos. Estos datos recibidos se deberan guardar en el archivo recibido_pid.txt (deberá conseguir 
el process ID del cliente para esto).        */

#include "my5.h"

int main (void)
{
        /*VARIABLES*/
        int fd_sock=0;  //Socket local
        struct sockaddr_in server;    //struct para colocar datos en connect()
        char buffer[TAM], cat1[]={"recibido_"}, cat2[]={".txt"}, *p1=NULL, *p2=NULL, *Namefile=NULL;
        char msg[]={"Mensaje recibido"};
        int pid=getpid();
        FILE *fd=NULL;

        int port=50000, i=0;
        char host[]={"127.0.0.1"};

        fd_sock=initSocketC(host, port, &server);

        if(connect (fd_sock, (struct sockaddr*) &server, sizeof(server) ) <0)
        {
                printf("Error - Al conectar\n");
                return -1;
        }

        p1=my_itoa(pid);
        p2=strcat(cat1, p1);
        Namefile=strcat(p2, cat2);

        //        printf("NAMEFILE=%s\n", Namefile );
        fd=fopen(Namefile, "w");        //Abro el archivo
        if(fd==NULL)
        {
                printf("Error - Al abrir el archivo\n");
                return 1;
        }

        for(i=0; i<2; i++)
        {
                if(read (fd_sock, buffer, sizeof(buffer) ) < 0 )        //Recibo la informacion
                {
                        printf("Error - Al leer\n");
                        return -1;
                }

                fwrite(buffer, sizeof(buffer), 1, fd);
                
                if(write (fd_sock, msg , sizeof(msg)  ) < 0 )
                {
                        printf("Error - Al leer\n");
                        return -1;
                }
        }
        fclose(fd);

        free(p1);

        return 0;
}




