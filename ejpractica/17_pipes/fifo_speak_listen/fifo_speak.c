#include "fifo.h"

int main (int argc, char **argv)
{
        int fd_fifo=0, escrito=0;
        char buffer[TAM];

        if(argc != 2)
        {
                printf("Invocar como ./main <fifoName>\n");
                return -1;
        }

        system("rm -f info1");

        fd_fifo=mkfifo(*(argv +1), 0666);
        if(fd_fifo < 0)
        {
                printf("Error - Al crear la fifo\n");
                return -1;
        }

        printf("Esperando a un lector...\n");

        fd_fifo=open(*(argv + 1) , O_WRONLY);
        if(fd_fifo < 0)
        {
                printf("Error - Al abrir la fifo\n");
                return -1;
        }
        printf("Ya puede escribir mensajes\n");
        do
        {
                fgets(buffer, TAM, stdin);
                escrito=write(fd_fifo, buffer, strlen(buffer) );
                if(escrito < 0)
                {
                        printf("Error - Al escribir en la fifo\n");
                        return -1;
                }

        } while(escrito > 1);

        close(fd_fifo);

        return 0;
}