#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (void)
{
        int child_pid=0;

        printf("Esto solo es un programa para dejar un proceso en sleep y poder cerrarlo con el comando en el bash\nkill <PID>\n\n");

        switch( child_pid= (int) fork() )
        {
                case -1: perror("fork");
                        return -1;
                
                case 0: 
                                printf("HIJO: PPID=%d\n", getppid() );
                                
                                while(1)        //se queda loopeando en sleep
                                {
                                        sleep(1);
                                }

                default:
                                printf("PADRE: pid del proceso hijo PID=%d\n", child_pid);

        }
        return 0;
}