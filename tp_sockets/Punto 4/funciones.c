#include "socket.h"

void interrupt(int signum)
{
        int rv=0, pid=0;
        signal(SIGCHLD, interrupt);     /*Reseteo la señal*/

        while ( (pid=waitpid(-1, &rv, WNOHANG) ) > 0)   //La options WNOHANG hace que se retorne si el hijo no existe
        {
                printf("\n---Saliendo del proceso hijo PID %d con status de salida %d---\n\n", pid, WEXITSTATUS(rv));
        }
}