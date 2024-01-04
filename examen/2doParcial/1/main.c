#include "my.h"


int main (void)
{
        FILE *fd_fifo=NULL;
        int fd=0, leidos=0, i=0, j=0, k=0, cant=0 ;
        float MemFree_prom=0, MemAvailable_prom=0, SwapFree_prom=0;
        char buffer[TAM], *p=NULL, *str=NULL;
        char registro[3][50]={"MemFree", "MemAvailable", "SwapFree"};
        struct mem datos;
        struct cola circular;

        fd=mkfifo("stats_meminfo", 0666);          //Creo la fifo
        if(fd < 0)
        {
                perror("Error al crear la fifo\n");
                exit(-1);
        }

        cola_init(&circular);   //Inicializo la cola

        fd=open("/proc/meminfo", O_RDONLY);
        if(fd < 0)
        {
                perror("Error - Al abrir el archivo\n");
                exit(-1);
        }


        while(1)                 //Tomo datos siempre, le faltaria una condicion de salida que no decia en el ejercicio
        {
                leidos=read(fd, buffer, TAM);
                if(leidos < 0)
                {
                        perror("Error - Al leer el archivo");
                        exit(-1);
                }

                cant++;         //Cantidad de estructuras leidas hasta el momento
                for(j=0; j<3; j++)
                {
                        p=strstr(buffer, *(registro + j));              //Hago un substring con los nombres de las cosas que quiero buscar

                        for(i=0; *(p+i)<'0' || *(p+i)> '9'; i++) { }  //Me fijo donde empiezan los numeros
                        p=p+i;          //Seteo el puntero donde empiezan los numeros

                        str=(char *) malloc(sizeof(char) );
                        if(str==NULL)
                        {
                                perror("Error - Al asignar memoria\n");
                                exit(-1);
                        }

                        for(i=0; *(p+i)>='0' && *(p+i)>='9'; i++)            //Mientras que lea numeros, los guardo y hago realloc
                        {
                                *(str + i)=*(p+i);
                                str=(char *)realloc (str, sizeof(char) * (i+2) );
                                if(str==NULL)
                                {
                                        perror("Error - Al reasignar memoria\n");
                                        exit(-1);
                                }
                        }
                        *(str + i)='\0';        //Pongo el NULL

                        switch(j)
                        {
                                case 0: 
                                                datos.MemFree=atoi(str);
                                                break;
                                
                                case 1: 
                                                datos.MemAvailable=atoi(str);
                                                break;
                                
                                case 2: 
                                                datos.SwapFree=atoi(str);
                                                break;
                        }
                        
                        free(str);
                }

                push(&circular, datos); //Meto los datos en la cola

                if(circular.flag_lleno == 1)
                {         
                        k++;
                } 

                if(k==5)        //Si pasan 5 min con la cola llena, es decir, tengo 20 datos, hago el promedio
                {
                        for(i=0, MemFree_prom=0, MemAvailable_prom=0, SwapFree_prom=0; i<20; i++)
                        {
                                MemFree_prom+= circular.buffer[i].MemFree;
                                MemAvailable_prom+= circular.buffer[i].MemAvailable;
                                SwapFree_prom += circular.buffer[i].SwapFree;
                        }

                        MemFree_prom= (float)MemFree_prom/20;
                        MemAvailable_prom= (float)MemAvailable_prom/20;
                        SwapFree_prom = (float) SwapFree_prom/20;

                        fd_fifo=fopen("stats_meminfo", "w");         //Abro la fifo
                        if(fd_fifo <0)
                        {
                                perror("Error - Al abrir la fifo");
                        }

                        fprintf(fd_fifo,"%ld;%0.2f;%0.2f;%0.2f", time(NULL), MemFree_prom, MemAvailable_prom, SwapFree_prom);           
                        k=0;            //pongo 5 en 0 para volver  a contar otros 5 min con el buffer lleno

                        fclose(fd_fifo);     //Una vez que mando los datos cierro la fifo
                }
                sleep(60);      //Porque tomo datos por minuto
        }

        close(fd);

        return 0;
}