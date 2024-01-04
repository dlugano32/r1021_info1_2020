/**
 * -Usando la función de wait() en el padre.
 * Recibe la señal de salida del proceso hijo, con posibilidad de saber cual es su status de salida
 * -->Desventajas: Es bloqueante, es decir hasta que el proceso hijo no termine,el padre no puede seguir
 * */
//ver en la consola con el comando --> watch -n 1 "ps elf | grep tcp | grep -v grep"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include<sys/wait.h>

int main (void)
{
        int pid=0, child_pid=0, rv=0, i=0;

        if((pid=fork()) <0)
        {       
                perror("fork\t");
                return -1;
        }

        if(pid==0)      /*Proceso hijo*/
        {
                for(i=8; i>0; i--)
                {
                        fflush(stdout);
                        printf("Proceso hijo PID %d termina en %d\n", i, getpid() );
                        sleep(1);
                }
        }
        else    /*Proceso padre*/
        {
                printf("Proceso padre PID %d esperando a que termine el hijo\n", getpid() );
                child_pid=wait(&rv);    //      BLOQUEO-->El programa se queda trabado aca hasta que el proceso hijo termine
                printf("---SIGCHLD recibida\nProceso hijo PID=%d termino con status de salida %d\n", child_pid, WEXITSTATUS(rv) );
                
                while(1)
                {
                        sleep(1);
                }
        }
        
        return (0);
}