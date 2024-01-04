#include "my.h"

int main(void)
{
        int fifo_recv=0, fifo_send=0;
        char str[TAM], Pal_si[]={"La palabra es un palindromo"}, Pal_no[]={"La palabra NO es un palindromo"};

        fifo_recv=open("fifo_1", O_RDONLY);
        if(fifo_recv < 0)
        {
                perror("Error - Al abrir la fifo\t");
                return -1;
        }

        if( read(fifo_recv, str, TAM) <0)
        {
                perror("Error - Al leer la fifo\t");
                return -1;
        }

        fifo_send=open("fifo_2", O_WRONLY);
        if(fifo_send < 0)
        {
                perror("Error - Al abrir la fifo\t");
                return -1;
        }

        if( palindromo(str) == 1 )
                {
                        if( write(fifo_send, Pal_si, strlen(Pal_si) ) < 0)
                        {
                                perror("Al escribir en la fifo\n");
                                return -1;
                        }
                }
                else
                {
                        if( write(fifo_send, Pal_no, strlen(Pal_no) ) < 0)
                        {
                                perror("Al escribir en la fifo\n");
                                return -1;
                        }
                }

                close(fifo_send);
                close(fifo_recv);
}
