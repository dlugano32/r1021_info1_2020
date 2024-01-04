#include "my.h"

int main(void)
{
        pid_t pid=0;
        int ch_fifo=0, p_fifo=0;
        char str[TAM], Pal_si[]={"La palabra es un palindromo"}, Pal_no[]={"La palabra NO es un palindromo"};

        system("rm -f info1*");

        pid=fork();     //Bifurco el programa

        if(pid < 0)
        {
                printf("Error - En el fork\n");
                return -1;
        }
        else if(pid == 0)       //Proceso hijo
        {
                ch_fifo=mkfifo("info1_c", 0666);
                if(ch_fifo < 0)
                {
                        perror("Error - Al crear la fifo\n");
                        return -1;
                }

                printf("CHILD: Ingrese una palabra y se le indicara si es palindromo\n");
                scanf("%s", str);
                ch_fifo=open("info1_c", O_WRONLY);
                if(ch_fifo < 0)
                {
                        perror("Error - Al abrir la fifo\n");
                }

                if( write(ch_fifo, str, TAM) < 0)
                {
                        printf("Error - Al escribir en la fifo\n");
                        return -1;
                }                

                printf("CHILD: Esperando una respuesta\n");
                p_fifo=open("info1_p", O_RDONLY);
                if(p_fifo < 0)
                {
                        perror("Error - Al abrir la fifo\n");
                        return -1;
                }

                if( read(p_fifo, str, TAM ) < 0)
                {
                        printf("Error - Al escribir en la fifo\n");
                        return -1;
                }

                printf("CHILD: Mensaje recibido:\t%s\n", str);

                close(p_fifo);
                close(ch_fifo);
                return 0;
        }
        else //Proceso padre
        {
                //declaro un signal handler para no dejar procesos en estado zombie
                signal(SIGCHLD, SIG_IGN);

                p_fifo=mkfifo("info1_p", 0666);
                if(p_fifo < 0)
                {
                        perror("Error - Al crear la fifo\n");
                        return -1;
                }

                printf("PARENT: Esperando una palabra de mi hijo\n");
                ch_fifo=open("info1_c", O_RDONLY);
                if(p_fifo < 0)
                {
                        perror("Error - Al abrir la fifo\n");
                        return -1;
                }

                if( read(ch_fifo, str, TAM) < 0)
                {
                        printf("Hola-Error - Al leer en la fifo\n");
                        return -1;
                }

                p_fifo=open("info1_p", O_WRONLY);
                if(p_fifo < 0)
                {
                        perror("Error - Al abrir la fifo\n");
                        return -1;
                }
                
                if( palindromo(str) == 1 )
                {
                        if( write(p_fifo, Pal_si, strlen(Pal_si) ) < 0)
                        {
                                perror("Al escribir en la fifo\n");
                                return -1;
                        }
                }
                else
                {
                        if( write(p_fifo, Pal_no, strlen(Pal_no) ) < 0)
                        {
                                perror("Al escribir en la fifo\n");
                                return -1;
                        }
                }

                close(p_fifo);
                close(ch_fifo);
        }
        
        return 0;
}