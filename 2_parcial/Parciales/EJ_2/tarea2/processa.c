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
        
        printf("Ingrese una palabra por teclado y se va a determinar si es capicua\n");
        scanf("%s", str);

        fifo_send=open("fifo_1", O_WRONLY);
        if(fifo_send<0)
        {
                perror("Error - Al abrir la fifo\t");
                return -1;
        }

        if( write(fifo_send, str, TAM) < 0)
        {
                perror("Error - Al escribir en la fifo\t");
                return -1;
        }

        fifo_recv=open("fifo_2", O_RDONLY);
        if(fifo_recv<0)
        {
                perror("Error - Al abrir la fifo\t");
                return -1;
        }

        if( read(fifo_recv, str, TAM) <0 )
        {
                perror("Error - Al leer la fifo");
                return -1;
        }

        printf("Mensaje recibido:\n%s\n", str);

        close(fifo_send);
        close(fifo_recv);

        return 0;
}