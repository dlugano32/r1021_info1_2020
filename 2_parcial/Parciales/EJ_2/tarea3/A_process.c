#include "my.h"

int main(void)
{
        int fifo_recv=0, fifo_send=0;
        char str[TAM];

        system("rm -f fifo_*");
        
        fifo_send=mkfifo("fifo_1", 0666);
        if(fifo_send <0)
        {
                perror("Error - Al crear la fifo\t");
                return -1;
        }

        fifo_recv=mkfifo("fifo_2", 0666);
        if(fifo_recv <0)
        {
                perror("Error - Al crear la fifo\t");
                return -1;
        }

        printf("Ingrese una palabra para conocer su sinonimo\n");        
        scanf("%s", str);

        fifo_send=open("fifo_1", O_WRONLY);
        if(fifo_send <0)
        {
                perror("Error - Al abrir la fifo\t");
                return -1;
        }

        if( write(fifo_send, str, strlen(str) ) <0)
        {
                perror("Error - Al escribir en la fifo\t");
                return -1;
        }

        fifo_recv=open("fifo_2", O_RDONLY);
        if( fifo_recv <0 )
        {
                perror("Error - Al abrir la fifo\t");
                return -1;
        }

        memset(str, 0, TAM);

        if( read(fifo_recv, str, TAM) <0)
        {
                perror("Error - Al leer en la fifo\t");
                return -1;
        }

        printf("Mensaje recibido\t%s\n", str);

        close(fifo_recv);
        close(fifo_send);
        return 0;
}