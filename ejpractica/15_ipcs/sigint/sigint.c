/*Solo un ejercicio de demostracion de como interceptar signals de SIGINT que es cuando apretas Ctrl+c*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void interrupt(int);

int main (void)
{
        //Asigno el handler de la señal SIGINT
        signal(SIGINT, interrupt);
        
        printf("Mi PID es %d\n", getpid());

        while(1)        //El loop simularia un programa cualquier en proceso
        {
                printf(".");
                fflush(stdout);
                sleep(1);
        }

        return 0;
}

void interrupt(int signum)
{
        signal(SIGINT, interrupt);
        /* NOTE some versions of UNIX will reset signal to default
	after each call. So for portability reset signal each time */

        /*En este tipo de funciones no puedo usar funciones como printf por problemas de compatibilidad*/
        static int i=0;
        char msg1[]={"\n\n¿Estas seguro de que quiere salir del programa? \nPor favor ingrese Ctrl+c otra vez en ese caso\n"};
        char msg2[]={"Saliendo del programa\n"};

        if(i==0)
        {
                //En el primer intento no salgo del programa por si tiene que guardar algun progreso o algo
                write(1, msg1, strlen(msg1));
                i++;
        }else
        {
                //En el segundo intento sale del programa
                //Se deberia liberar memoria, cerrar archivos, conexiones, etc
                write(1, msg2, strlen(msg2));
                exit(signum);
        }
}
