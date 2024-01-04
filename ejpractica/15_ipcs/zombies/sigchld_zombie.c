/**
 * -Ignorando la señal SIGCHLD en el padre. Recibe la señal de salidad del hijo pero la ignora, es decir no interesa sabercomo termino. 
 * El hijo puede terminar el proceso, porque el padre recibe la señal.
 * -->Ventajas: No es bloqueante
 * -->Desventajas: No es posible saber el status de salida
 * */
//ver en la consola con el comando --> watch -n 1 "ps elf | grep tcp | grep -v grep"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include<sys/wait.h>

int main (void)
{
        int pid=0;

        if( (pid=fork()) < 0)
        {
                perror("fork\t");
                return -1;
        }

        if(pid==0)
        {
                int i=0;
                for(i=8; i>0; i--)
                {
                        fflush(stdout);
                        printf("Proceso hijo PID %d termina en %d\n", i, getpid());
                        sleep(1);
                }
        }
        else
        {
                /*Seteamos el handler para recibir la señal del proceso hijo pero ignorarla*/
                signal(SIGCHLD, SIG_IGN);
                printf("Proceso padre PID %d corriendo normalmente\n", getpid());

                while(1)
                {
                        sleep(1);
                }
        }
        return(0);
}
