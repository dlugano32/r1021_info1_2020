#include "my.h"

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

int initSocketS(struct conf *load, struct sockaddr_in *local)
{
        int s=0;

        s= socket(AF_INET, SOCK_STREAM,0); 
        if(s<0)
        {
                perror("No se pudo crear el socket");
                exit(1);
        }

        /*CONFIGURO LA STRUCT sockaddr_in*/
        local->sin_family=AF_INET;
        local->sin_port=htons(load->port);   
        local->sin_addr.s_addr=htonl(INADDR_ANY);
        memset((void *) &(local->sin_zero), '\0', 8);

        /*PASO 2 :bind()*/
        if ( bind(s, (struct sockaddr *) local, sizeof( *local )) < 0)
        {
                perror("Asignando direccion");
                exit(1);
        }

        /*PASO 3: listen() y accept () */
        listen(s, load->backLog);

        return s;
}

struct listado listar ( char *archStr)
{
        struct listado data;
        int i=0, j=0;
        char *buffer=NULL, *p=NULL;

        data.str = (char **)malloc( sizeof(char*) );
        if(data.str ==NULL )
        {
                printf("Error - Asingando memoria\n");
                exit(-1);
        }

        for(i=0, data.cant=1 ; *(archStr+i)!='\0'; i++)         //cuento cuantos nombres de archivos tengo
        {
                if(*(archStr+ i) == ',' )
                {
                        data.cant++;
                }
        }

        if(data.cant==1)        //si tengo uno solo no tengo ninguna coma
        {
                p=(char*) malloc(sizeof(char)* strlen(archStr) );
                strcpy(p, archStr);
                data.str[0]=p;
        }
        else    //si tengo mas de uno se procede de la siguiente manera
        {
                buffer=strtok(archStr, ",");    //seteo al string que quiero hacerle tokens
                p=(char*) malloc( sizeof(char) * (strlen(buffer)+1) );      //pido memoria para el string
                strcpy(p, buffer);
                data.str[0]=p;

                for(i=1, j=0; i<data.cant; i++, j++)    //Le hago los tokens que faltan con el string setead
                {      
                        data.str = (char **)realloc(data.str, sizeof(char*) * (j+2) );  //Hago realloc del vector de punteros para ingresar mas strings
                        buffer=strtok(NULL, ",");       
                        p=(char*) malloc( sizeof(char) * (strlen(buffer)+1) );
                        strcpy(p, buffer);
                        data.str[i]=p;
                }
        }

        return data;
}

void threadTransfer(int f_sock, char ** archStr, int cant)
{
        int i=0, length=0, transfer=0;
        char *str, buffer[TAM];
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

                transfer=read(f_sock, buffer, TAM );
                if(transfer < 0)
                {
                        printf("Error- Al transferir datos");
                        exit(1);
                }

                printf("%s\n", buffer);
                
                free(str);
                fclose(fp);
        }
}

void interrupt(int signum)
{
        int rv=0, pid=0;
        signal(SIGCHLD, interrupt);     /*Reseteo la señal*/

        while ( (pid=waitpid(-1, &rv, WNOHANG) ) > 0)   //La options WNOHANG hace que wait no sea bloqueante
        {
                printf("\n---Saliendo del proceso hijo PID %d con status de salida %d---\n\n", pid, WEXITSTATUS(rv));
        }
}