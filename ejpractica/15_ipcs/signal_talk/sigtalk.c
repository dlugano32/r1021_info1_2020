/*Es un programa que hace una comunicacion IPCs entre un programa padre y un programa hijo*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void sigint(int);
void sigterm(int);
void sigquit(int);

int main (void)
{
        int pid;

        if( (pid=fork()) <0)
        {
                perror("fork\t");
                return -1;
        }

        if(pid==0)      /*PROCESO HIJO*/
        {
                //Seteo los handler de los signals
                signal(SIGINT, sigint);
                signal(SIGTERM, sigterm);
                signal(SIGQUIT, sigquit);
                printf("---Proceso hijo PID %d esperando instrucciones del padre...\n", getpid());
                while(1)
                {
                        sleep(1);
                }
        }
        else    /*PROCESO PADRE*/
        {
                printf("---Proceso padre PID %d\n", getpid() );
                printf("Proceso padre enviando signal: SIGINT\n");
                kill(pid, SIGINT);
                sleep(2);       //Hago una pausa de 2seg
                printf("Proceso padre enviando signal: SIGQUIT\n");
                kill(pid, SIGQUIT);
                sleep(2);       //Hago una pausa de 2seg
                printf("Proceso padre enviando signal: SIGTERM\n");
                kill(pid, SIGTERM);
                
                
        }
        
        return (0);
}

void sigint(int signum)
{
        signal(SIGINT, sigint);         //Vuelvo a setear la señal
        char msg[]={"Proceso hijo: Signal SIGINT recibida\n"};
        write(1, msg, strlen(msg) );
}

void sigterm(int signum)
{
        signal(SIGTERM, sigterm);         //Vuelvo a setear la señal
        char msg[]={"Proceso hijo: Signal SIGTERM recibida\nCerrando programa\n"};
        write(1, msg, strlen(msg) );

        exit(signum);
}

void sigquit(int signum)
{
        signal(SIGQUIT, sigquit);         //Vuelvo a setear la señal
        char msg[]={"Proceso hijo: Signal SIGQUIT recibida\n"};
        write(1, msg, strlen(msg) );
}