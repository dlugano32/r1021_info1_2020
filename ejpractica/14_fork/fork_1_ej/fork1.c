#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (void)
{
        int status=0, child_pid=0;

        switch( child_pid= (int) fork() )
        {
                case -1: perror("fork");
                        return -1;
                
                case 0: 
                                printf("HIJO: Este es el proceso hijo PID= %d\n", getpid() );
                                printf("HIJO: parents process ID PPID=%d\n", getppid() );
                                printf("HIJO: Ingresa mi status de salida\n");
                                scanf("%d", &status);
                                printf("HIJO: Chau!\n");
                                exit(status);

                default:
                                printf("PADRE: Este es el proceso padre PID=%d\n", getpid() );
                                printf("PADRE: El numero de proceso de mi hijo es PID=%d\n", child_pid);
                                printf("PADRE: Estoy esperando a que mi hijo para terminar el programa\n");
                                wait(&status);
                                printf("PADRE: El status de salida de mi hijo es: %d\n", WEXITSTATUS(status) );
                                printf("PADRE: Chau!\n");

        }

        return 0;
}
