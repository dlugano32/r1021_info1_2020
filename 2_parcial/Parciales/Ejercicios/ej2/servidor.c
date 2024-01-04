#include "socket.h"

//Variables globales
int flag=0, j=0;
struct ciudad **vec=NULL;

int main (void)
{
        //VARIABLES
        int s=0;         // file descriptor del socket
        int n_sock=0;    //file descriptor del canal de datos usada por aceppt
        struct sockaddr_in cliente;       //struct para colocar datos en aceppt()
        socklen_t l_cliente=sizeof(cliente);         //variable para guardar el tamaño de la estructura cliente usada en aceppt()
        char msg[]={"OK"};
        int portn=50000;        //Puerto usada para mandar datos
        int i=0, ya_existe=0;

        struct ciudad buffer;

        vec=(struct ciudad**) malloc(sizeof(struct ciudad*) );
        if(vec==NULL)
        {
                printf("Error - Al asingar memoria\n");
                return -1;
        }

        //Seteo los signal handlers
        signal(SIGINT, interrupt1);

        s=initSocketS( portn, &cliente);

        while(flag != 1)        //loop donde el server va a estar conectado y disponible para transmitir
        {
                printf("Esperando conexiones...\n");
                n_sock = accept(s, (struct sockaddr *) &cliente, &l_cliente);  
                if(n_sock < 0)
                {
                        perror("Al aceptar el cliente");
                        return -1;
                }

                if( write(n_sock, msg, strlen(msg) ) <0)
                {
                        printf("Error - Al escribir en el socket\n");
                        return -1;
                }

                if( read(n_sock, &buffer, sizeof(struct ciudad)) <0)
                {
                        printf("Error - Al leer en el socket\n");
                        return -1;
                }

                close(n_sock);

                for(i=0, ya_existe=0; i<j ; i++)
                {
                        if( strcmp(vec[i]->nombre,buffer.nombre) == 0)
                        {
                                if( vec[i]->mesa.nro == buffer.mesa.nro )
                                {
                                        ya_existe=1;
                                }
                        }
                }

                if(ya_existe ==1)
                {
                        printf("Información rechazada\n");
                }
                else
                {  
                        vec=(struct ciudad **) realloc(vec, sizeof(struct ciudad) *(j+1));
                        vec[j]=(struct ciudad *) malloc( sizeof(struct ciudad) );

                        //Transfiero los datos;
                        vec[j]->mesa=buffer.mesa;
                        strcpy(vec[j]->nombre, buffer.nombre);
                        j++;
                }
                close(n_sock);
        }

        close(s);
        return 0;
}

void interrupt1(int signum)
{
        int i=0, k=0, Votos_tot=0, Votos_A=0, Votos_B=0, Vot_blanco=0;
        float res_A=0, res_B=0;
        struct ciudad *aux=NULL;

        signal(SIGUSR1, interrupt1);    //Reseteo la señal
        
        //Hago el recuento de votos
        printf("Cantidad de mesas escrutadas = %d\n", j);       //j es la cantidad de mesas escrutadas
        for(i=0; i<j; i++)
        {
                Votos_tot+=vec[i]->mesa.votosa;
                Votos_tot+=vec[i]->mesa.votosb;
                Votos_tot+=vec[i]->mesa.blancos;
                Votos_B+=vec[i]->mesa.votosb;
                Votos_A+=vec[i]->mesa.votosa;
                Vot_blanco+=vec[i]->mesa.blancos;
        }

        //Asigno los votos en blanco
        if(Votos_A>Votos_B)
        {
                Votos_A+=Vot_blanco;
        }
        else
        {
                Votos_B+=Vot_blanco;
        }

        printf("Votos_A = %d\nVotos_B= %d\n", Votos_A, Votos_B);
        
        //Saco los porcentajes
        res_A=( (float) Votos_A/ (float) Votos_tot) * 100;
        res_B=( (float) Votos_B/ (float) Votos_tot) * 100;

        printf("El porcentaje del postulante A es %0.3f\n", res_A);
        printf("El porcentaje del postulante B es %0.3f\n", res_B);

        //me fijo quien es el ganador
        if(res_A > res_B)
        {
                printf("El ganador de la votacion es el postulante A\n");

                //Ordeno el vector de estructuras 
                for(i=0; i<j-1 ; i++)           
                {
                        for(k=0; k< (j -i -1); k++ )
                        {
                                if ( vec[k]->mesa.votosa < vec[k+1]->mesa.votosa) 
                                {
                                        aux = vec[k];
                                        vec[k] = vec[k+1];
                                        vec[k+1] = aux;
                                }
                        }
                }

                printf("Las 5 ciudades con mas votos a favor del postulante A son:\n");
                if(j>5)
                {
                        for(i=0; i<5; i++)
                        {
                                printf("Ciudad: %s\tVotos A = %d\n", vec[i]->nombre, vec[i]->mesa.votosa);
                        }
                }
                else
                {
                        for(i=0; i<j; i++)
                        {
                                printf("Ciudad: %s\tVotos A = %d\n", vec[i]->nombre, vec[i]->mesa.votosa);
                        }                        
                }
        }
        else
        {
                printf("El ganador de la votacion es el postulante B\n");

                //Ordeno el vector de estructuras 
                for(i=0; i<j-1 ; i++)
                {
                        for(k=0; k< (j -i -1); k++ )
                        {
                                if ( vec[k]->mesa.votosb < vec[k+1]->mesa.votosb) 
                                {
                                        aux = vec[k];
                                        vec[k] = vec[k+1];
                                        vec[k+1] = aux;
                                }
                        }
                }

                printf("Las 5 ciudades con mas votos a favor del postulante B son:\n");
                if(j>5)
                {
                        for(i=0; i<5; i++)
                        {
                                printf("Ciudad: %s\tVotos B = %d\n", vec[i]->nombre, vec[i]->mesa.votosb);
                        }
                }
                else
                {
                        for(i=0; i<j; i++)
                        {
                                printf("Ciudad: %s\tVotos B = %d\n", vec[i]->nombre, vec[i]->mesa.votosb);
                        }                        
                }
        }
        

        //Libero recursos
        for(i=0; i<j; i++)
        {
                free(*(vec +i));
        }
        free(vec);

        flag=1;
        exit(0);
}