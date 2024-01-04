#include "my.h"

int main (int argc, char **argv)
{
        //Variables para la conexion
        int s=0, port=50000;
        struct sockaddr_in server;    //struct para colocar datos en connect()
        char IP[]={"127.0.0.1"};

        //Variables
        FILE *fp=NULL;
        int length=0;
        char *str=NULL;

        if(argc != 2)
        {
                printf("Invocar como ./main <in.txt>\n");
                exit(-1);
        }
        
        //Llamo a una funcion que abre el socket para conectarme al server
        s=initSocketC(port, IP, &server);
        if(s==-1)
        {
                printf("Error - En la funcion initSocketC");
                exit(-1);
        }

        //Me conecto al server
        if(connect (s, (struct sockaddr*) &server, sizeof(server) ) <0)
        {
                perror("Al conectar\n");
                return -1;
        }

        fp=fopen(*(argv +1), "r");
        if(fp==NULL)
        {
                perror("Error - Al abrir el archivo\n");
                exit(-1);
        }

        //Averiguo el largo del file
        fseek(fp, 0,SEEK_END);
        length=ftell(fp);
        rewind(fp);

        str=(char*)malloc( sizeof(char) * length);      //Tomo memoria del largo del archivo
        if(str==NULL)
        {
                perror("Error - Al asignar memoria\n");
                exit(-1);
        }
        
        fread(str, length, 1, fp);      //Leo todo el contendio del archivo
        *(str+length-1)='\0';

        if(write(s, str, length) < 0)           //Mando el contenido del archivo por el socket
        {
                perror("Al escribir en el socket\n");
                exit (-1);
        }

        //Libero recursos
        free(str);
        fclose(fp);
        close(s);

        return 0;
}