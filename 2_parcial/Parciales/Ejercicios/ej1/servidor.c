#include "my.h"

/*Variable Global usada por el signal handler*/
int flag =0, j=0;
struct data **vec=NULL;

int main (void)
{
        //VARIABLES para la conexion
        int s=0;         // file descriptor del socket
        int n_sock=0;    //file descriptor del canal de datos usada por aceppt
        struct sockaddr_in cliente;       //struct para colocar datos en aceppt()
        socklen_t l_cliente=sizeof(cliente);         //variable para guardar el tamaño de la estructura cliente usada en aceppt()
        //VARIABLES para la comunicacion
        char buffer[TAM], msg[]={"OK"}, *p=NULL;
        int portn=50000;        //Numero de puerto utilizado

        int leidos =0, cant=0, i=0;
        
        alarm(30);      //Seteo la alarma para que se dispare cada 30 seg

        vec=(struct data **) malloc(sizeof(struct data *) );
        if(vec==NULL)
        {
                printf("Error - Al asignar memoria\n");
                return -1;
        }

        //Declaro los signal handler
        signal(SIGALRM, interrupt1);
        signal(SIGUSR1, interrupt2);

        s=initSocketS(portn, &cliente);

        while(flag != 1)        //loop donde el server va a estar conectado y disponible para transmitir
        {
                printf("Esperando conexiones...\n");
                n_sock = accept(s, (struct sockaddr *) &cliente, &l_cliente);  
                if(n_sock < 0)
                {
                        perror("Al aceptar el cliente");
                        return -1;
                }
                else
                {
                        if( write(n_sock, msg, strlen(msg)) <0 )
                        {
                                printf("Error - Al escribir en el socket\n");
                                return -1;
                        }       
        
                        if( ( leidos=(int) read(n_sock, buffer, TAM) ) <0 )
                        {
                                printf("Error - Al escribir en el socket");
                                return -1;
                        }
                        
                        close(n_sock);          //Una vez leido todo cierro la comunicacion

                        for(i=0, cant=0; *(buffer + i)!='\0'; i++)      //lineas = la cantidad de lineas de datos que ingresan
                        {
                                if(*(buffer +i) == '\n' )
                                {
                                        cant++;
                                }
                        }
                        
                        /*Hago la primera iteracion del buffer afuera del for porque el strtok necesita tener el puntero de donde va a hacer tokens primero*/
                        vec=(struct data **) realloc(vec, sizeof(struct data*) * (j+1));
                        vec[j]=(struct data*) malloc(sizeof(struct data));
                        if(vec==NULL)
                        {
                                printf("Error - Al reasignar memoria\n");
                                return -1;
                        }
                        p=strtok(buffer, ",");     //Guardo ciudad
                        strcpy(vec[j]->ciudad, p);
                        
                        p=strtok(NULL, ",");    //Guardo codigo postal
                        vec[j]->codpost=atoi(p);

                        p=strtok(NULL, "\n");           //Guardo superficie
                        vec[j]->sup=atof(p);
                        j++;
                        
                        for(i=0; i<(cant-1); i++, j++)              //j++ Cantidad de structuras leidas de todos los clientes
                        {         
                                vec=(struct data **) realloc(vec, sizeof(struct data*) * (j+1) );
                                vec[j]=(struct data*) malloc(sizeof(struct data) );
                                if(vec==NULL)
                                {
                                        printf("Error - Al reasignar memoria\n");
                                        return -1;
                                }
                                p=strtok(NULL, ",");     //Guardo ciudad
                                strcpy(vec[j]->ciudad, p);
                                
                                p=strtok(NULL, ",");    //Guardo codigo postal
                                vec[j]->codpost=atoi(p);

                                p=strtok(NULL, "\n");           //Guardo superficie
                                vec[j]->sup=atof(p);
                        }
                        printf("%d Datos leidos\n", j);

                        for(i=0; i<j; i++)
                        {
                                printf("Ciudad= %s\tCod. postal =%d\tSuperficie= %0.2f\n", vec[i]->ciudad, vec[i]->codpost, vec[i]->sup);
                        }
                }
        }

        
        close(s);

        for(i=0; i<j; i++)
        {
                free(*(vec +i));
        }
        free(vec);
        //free(str);
        return 0;
}

void interrupt1(int signum)     //Alarm
{
        signal(SIGALRM, interrupt1);    //Reseteo el signal;

        FILE *fp=NULL;
        int i=0;

        printf("Guardando datos...\n");

        fp=fopen("out.bin", "w");
        if(fp==NULL)
        {
                printf("Error al crear el archivo\n");
        }

        for(i=0; i<j; i++)
        {
                fwrite(&vec[i], sizeof(struct data), 1, fp);
        }

        fclose(fp);
}

void interrupt2(int signum)     //Funcion para dejar de aceptar conexiones
{
        signal(SIGUSR1, interrupt2);    //Reseteo el signal
        flag=1;
}