/*Implemente una función que lea un archivo de texto desde el final hacia el principio y lo escriba en una FIFO, que debe ser creada por la función.

El prototipo de la función es el siguiente:
	int enviarInvertido (char *fifoName, char *fileName);
Donde:
	fifoName: Es el nombre de la fifo que debe crear la función y donde debe escribir el texto cifrado.
	fileName: El nombre del archivo de texto a enviar.
Devuelve:
	Un número positivo indicando la cantidad de caracteres escritos en la fifo y un número negativo en caso de error.
		-1 : Si no puede crear la fifo.
		-2 : Si no puede abrir el archivo.
		-3 : Si no puede leer el archivo.
		-4 : Si no puede escribir en la fifo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int enviarInvertido (char *, char *);

int main (void)
{
        enviarInvertido("info1", "in.txt");
        return 0;
}

int enviarInvertido (char *fifoName, char *fileName)
{
        int fd_fifo=0, length=0, i=0;
        FILE *fd_file=NULL;
        char *str;

        fd_fifo=mkfifo(fifoName, 0666);
        if(fd_fifo < 0)
        {
                perror("Error - Al crear la fifo\n");
                return -1;
        }

        fd_fifo=open(fifoName, O_WRONLY);
        if(fd_fifo < 0)
        {
                perror("Error - Al crear la fifo\n");
                return -1;
        }

        fd_file=fopen(fileName, "r");
        if(fd_file == NULL)
        {
                printf("Error - No se pudo abrir el archivo\n");
                return -2;
        }

        //BUSCO EL TAMAÑO DEL ARCHIVO
        fseek(fd_file, 0, SEEK_END);
        length=ftell(fd_file);
        rewind(fd_file);

        //TRANSFIERO LOS DATOS AL STR
        str=(char *) malloc(sizeof(char) * length +1);
        if(str==NULL)
        {
                printf("Error - Al asignar memoria\n");
                return 1;
        }

        if( fread(str, length, 1, fd_file ) < 0)
        {
                printf("Error - Al leer el archivo\n");
                return -3;
        }

        for(i=length-1; i>=0 ; i--)
        {       
                if( write(fd_fifo, str+i, 1) < 0)
                {
                        printf("Error - Al escribir en la fifo\n");
                        return -4;
                }
        }

        free(str);
        fclose(fd_file);

        return 0;
}