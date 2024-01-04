#include "my5.h"

int initSocketC( char * IP, int port, struct sockaddr_in *server)
{
        /*VARIABLES*/
        int s=0;        //file descriptor del socket usado en socket()
        struct hostent *sv;       //struct para usar en gethostbyname()

        s=socket(AF_INET, SOCK_STREAM, 0);
        if(s<0)
        {
                perror("No se pudo crear el socket");
                return -1;
        }

        sv=gethostbyname(IP);      //Obtengo la direccion IP donde está el servidor
        if(sv==NULL)
        {
                perror("No existe el servidor\n");
                return -1;
        }

        /*CONFIGURO LA STRUCT sockaddr_in servidor*/
        server->sin_family=AF_INET;      // Dominio AF_INET para comunicaciones de procesos en diferentes maquinas a traves de internet (IPv4)
        server->sin_port=htons(port);    //Asignar el numero de puerto. Recordar asignar puertos mayores a 1024, que son los que estan reservados
        memcpy(&server->sin_addr.s_addr, sv->h_addr, sv->h_length);      //copio datos IP de la estructura sv a la estructura server
        
        return s;
}

char * my_itoa (int num)
{
        int i=0, j=0, length=0, flag=0;
        char *str=NULL, *str_r=NULL;
        
        str=(char *) malloc(sizeof(char));
        if(str==NULL)
        {
                printf("Error - En el malloc\n");
                exit(1);
        }

        if((num) < 0)
        {
                num= num * (-1);
                flag=1;
        }
        
        while( num > 0)
        {
                str[i]= num % 10 + '0';     //Tomo el digito menos significativo
                num= num/10;                //El digito que ya tome, lo borro dividiendolo x 10
                str=realloc(str, sizeof (char) * (i+2) );
                i++;
        }
        
        if(flag==1)
        {
                str[i]='-';
                str=realloc(str, sizeof (char) * (i+2) );
                i++;
        }

        str[i]='\0';

        /*Una vez que tengo el numero invertido, simplemente lo doy vuelta*/
        length=strlen(str);
        str_r=(char* )malloc(sizeof(char) * length);

       for(i=0, j= (length-1) ; i < length ; i++, j--)
       {
              *(str_r+i)=*(str+j); //copio en str_r el string invertido
       }
       str_r[length]= '\0'; //le seteo el null

       free(str);
        
        return str_r;
}