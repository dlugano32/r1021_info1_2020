#include "fifo.h"

int main (int argc, char **argv)
{
        int fd_fifo=0, leidos=0;
        char buffer[TAM];

        if(argc != 2)
        {
                printf("Invocar como ./main <fifoName>\n");
                return -1;
        }

        //Si la fifo ya esta creada no se puede volver a crear otra vez porque da error
        /*
        fd_fifo=mkfifo(*(argv +1), 0666);
        if(fd_fifo < 0)
        {
                printf("Error - Al crear la fifo\n");
                return -1;
        }
        */

       printf("Esperando a un escritor...\n");

       fd_fifo=open(*(argv + 1), O_RDONLY);
       if(fd_fifo < 0)
       {
               printf("Error - Al abrir la fifo\n");
               return -1;
       }
        printf("Listo para recibir mensajes:\n\n");
       do
       {
               leidos=read(fd_fifo, buffer, TAM);
               if(leidos < 0)
               {
                       printf("Error - Al leer de la fifo\n");
               }
               else if (leidos > 1)
               {
                       buffer[strlen(buffer)]='\0';
                        printf("%s", buffer );
               }
       } while (leidos > 1);

       close(fd_fifo);
       
        return 0;
}