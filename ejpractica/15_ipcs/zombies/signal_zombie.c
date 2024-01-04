/**
 *-Usamos un signal handler.
 *Recibe la señal del hijo, entra a la funcion desginada y usamos la funcion wait, en este caso puedo elegir saber el status de salida o no
 *-->Ventajas: No es bloqueante y puedo saber el status de salida 
 **/
//ver en la consola con el comando --> watch -n 1 "ps elf | grep tcp | grep -v grep"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include<sys/wait.h>

void interrupt(int);

int main (void)
{
        int pid=0, i=0;

        if( (pid=fork()) < 0)
        {
                perror("fork\t");
                return -1;
        }

        if(pid==0)
        {
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
                signal(SIGCHLD, interrupt);
                printf("Proceso padre PID %d corriendo normalmente\n", getpid());

                while(1)
                {
                        sleep(1);
                }
        }
        return(0);
}

void interrupt(int signum)
{
        int rv=0, pid=0;
        signal(SIGCHLD, interrupt);     /*Reseteo la señal*/

        pid=wait(&rv);
        printf("Proceso hijo PID %d ha sido cerrado exitosamente con status de salida %d\n", pid, WEXITSTATUS(rv));
}