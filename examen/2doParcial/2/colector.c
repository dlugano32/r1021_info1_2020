#include "my.h"

int main(void)
{
        FILE *fp=NULL, *fp_out=NULL;
        struct mem **vec=NULL, *aux=NULL;
        struct tm *tlocal;
        time_t timep;
        char * timer=NULL, *file=NULL, str[]={"stats_sistema_"}, extension[]={".txt"};
        int i=0, j=0;

        while(1)                //No decia condicion de salida
        {
                vec=(struct mem **) malloc( sizeof(struct mem *) * CANT);        //Asumiendo que la cola circular va a esta llena siempre. Voy a recibe 288 structs porque 288* 5 min = un dia
                if(vec==NULL)
                {
                        perror("Error - Al asignar memoria\n");
                        exit(-1);
                }

                for(i=0; i<CANT; i++)
                {
                        vec[i]=(struct mem *) malloc(sizeof(struct mem) );
                        if(vec[i]==NULL)
                        {
                                perror("Error - Al asignar memoria\n");
                                exit(-1);
                        }
                }

                for(i=0; i<CANT; i++)            //Hay 288 5 min en un dia
                {
                        fp=fopen("stats_meminfo", "r");         //lo abro cada 5 min
                        if(fp <0)
                        {
                                perror("Error - Al abrir la fifo");
                                exit(-1);
                        }        

                        fscanf(fp,"%d", &vec[i]->time_stap);        //Primero tomo el tiempo
                        fscanf(fp, "%f", &vec[i]->MemFree);
                        fscanf(fp, "%f", &vec[i]->MemAvailable);
                        fscanf(fp, "%f", &vec[i]->SwapFree);
                        
                        fclose(fp);
                        sleep(300);      //Los datos me llegan cada 300 seg
                }

                for(i=0; i<CANT-1 ; i++)                //lo ordeno de menor a mayor el time
                {
                        for(j=0; j< (CANT -i -1); j++ )
                        {
                                if ( vec[j]->time_stap < vec[j+1]->time_stap ) 
                                {
                                        aux = vec[j];
                                        vec[j] = vec[j+1];
                                        vec[j+1] = aux;
		                }
                       }
                }

                timep=time(NULL);
                tlocal=localtime(&timep);       //Tomo el tiempo local
                timer=(char *) malloc(sizeof(char) * 13);        //El tamaño de mi string YYYYMMDD+.txt+NULL
                strftime(timer,8,"%Y%m%d",tlocal);              //El puntero timer va a apuntar a YYYYMMDD

                strcat(timer, extension);       //YYYYMMDD.txt
                
                file_out(&file, str, timer);    //Le mando el puntero file para que me ponga ahi el nombre de mi archivo

                fp_out=fopen(file, "w");
                if(fp_out ==NULL )
                {
                        perror("Error - Al abrir el archivo del dia\n");
                        exit(-1);
                }

                for(i=0; i<CANT; i++)
                {
                        fwrite(&vec[i], sizeof(struct mem), 1, fp_out);
                }

                for(i=0; i<CANT; i++)
                {
                        free(vec[i]);
                }
                free(vec);
                free(file);
                free(timer);
                fclose(fp_out);
                fclose(fp);
        }

        return 0;
}