/*
3) Realizar una función threadTransfer() que recibirá un entero representando un socket, un vector de strings y un entero con su tamaño. 
La función deberá abrir cada archivo dentro del vector y transferir su contenido. Una vez transferidos todos los archivos finalizará.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void threadTransfer(int f_sock, char ** archStr, int cant);

int main(void)
{
        int f_sock=0;
        char *str[3]={"arch1.txt","arch2.txt","arch3.txt"};
        int cant=3;

        threadTransfer(f_sock, str, cant);

        return 0;
}

void threadTransfer(int f_sock, char ** archStr, int cant)
{
        int i=0, length=0, transfer=0;
        char *str;
        FILE *fp;

        for(i=0; i<cant; i++)
        {
                fp=fopen(archStr[i], "r");      //Abro el archivo
                if(fp==NULL)
                {
                        printf("Error - No se pudo abrir el archivo\n");
                        exit (1);
                }

                fseek(fp, 0, SEEK_END);
                length=(int) ftell(fp);         //Guardo el largo del archivo
                rewind(fp);
                str=(char*) malloc(sizeof(char) * length );     //Creo un string con el largo del file
                if(str ==NULL)
                {
                        printf("Error - Al asignar memoria en malloc\n");
                        exit (1);
                }

                fread(str, length, 1, fp);      //Leo todo el file
                transfer=write(f_sock, str, length);     //Transmito los datos, debido a que tengo el file descriptor del socket
                if(transfer < 0)
                {
                        printf("Error- Al transferir datos");
                        exit(1);
                }
                
                free(str);
                fclose(fp);
        }

}

