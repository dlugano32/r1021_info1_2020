/*
1) Escribir una función llamada load_conf() que tome un nombre de archivo (como cadena), lo abra y devuelva una estructura con los campos port, backLog y archStr 
que toma del archivo de configuración. El archivo tendrá el siguiente formato:
        PORT=num
        BACKLOG=num
        ARCHIVOS=arch01.txt,arch02.txt,…
No se sabe cuantos archivos vienen, pero a los fines de esta función es una cadena a leer que tienen como máximo 1024 caracteres. 
Para este ejercicio no puede utilizar strtok(), realicé la separación dentro de la función.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct conf
{
        int port;
        int backLog;
        char archStr[1024];
};
struct conf load_conf( char *FileName);

int main (void)
{
        struct conf ret;
        ret=load_conf("in.txt");

        printf("port\t%d\nbackLog\t%d\narchStr\t%s\n", ret.port, ret.backLog, ret.archStr);

        return 0;

}

struct conf load_conf( char *FileName)
{
        struct conf carga;
        char c='\0';
        int j=0;
        FILE * fd;

        fd=fopen(FileName, "r");

        for(j=0; j<3; j++)
        {
                c='\0';
                while(c != '=')
                {
                        c=fgetc(fd);
                }
                
                switch (j)
                {
                        case 0: 
                                        fscanf(fd,"%d", &carga.port);
                                        break;
                        case 1:
                                        fscanf(fd,"%d", &carga.backLog);
                                        break;
                        case 2:
                                        fscanf(fd, "%s", carga.archStr);
                                        break;
                }
        }
        return carga;
}