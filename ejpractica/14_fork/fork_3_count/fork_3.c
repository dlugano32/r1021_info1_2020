#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (void)
{
        int cont=0, child_pid=0;

        child_pid= (int) fork();

        if(child_pid <0)
        {       
                perror("fork");
                return -1;
        }
        else if(child_pid == 0) //child process
                {
                        int i=0;
                        printf("HIJO: Este es el proceso hijo\n");
                        printf("HIJO: PPID=%d\n", getppid() );
                        
                        for(i=0; i<5; i++)
                        {
                                cont ++;        // el contador de cada uno de los procesos va a ser diferente, son datos diferentes
                                printf("HIJO: %d\n", cont);
                                sleep(2);
                        }
                }

        else if(child_pid > 0) //parent process
                {
                        int j=0;
                        printf("PADRE: Este es el proceso padre\n");
                        printf("PADRE: pid del proceso hijo PID=%d\n", child_pid);

                        for(j=0; j<7; j++)
                        {
                                cont ++;        // el contador de cada uno de los procesos va a ser diferente, son datos diferentes
                                printf("PADRE: %d\n", cont);
                                sleep(1);
                        }
                }

        printf("Done!\n");
        return 0;
}