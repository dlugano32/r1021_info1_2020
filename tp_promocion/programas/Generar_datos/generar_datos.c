#include "my.h"


int main(void)
{
        FILE *fp=NULL;
        int i=0, j=0;
        char fileName[10];      //Conozco el largo del fileName "zonax.txt"
        struct medicion data;

        //Variables para las funciones de time.h
        time_t timep;
        char *timer=NULL;
        struct tm *tlocal;

        srand(time(NULL));      //Seteo la random seed con epoch

        //Zona;AAAAMMDD;HHMMSS;VOLT

        for(i=0; i<ZONAS; i++)
        {
                sprintf(fileName, "%s%d%s", "Zona", i, ".txt");         //Imprimo en el string el nombre de mi archivo

                fp=fopen(fileName, "w");
                if(fp==NULL)
                {
                        perror("Error - Al abrir el archivo");
                        exit(-1);
                }

                data.zona=i;    //Guardo el valor de la zona

                /*Seteo el tiempo en las 00.00 del dia actual. Lo que hago es restarle al dia actual, el resto de la division de EPOCH con 86400 que son los segundos que 
                conforman un dia. Lo que me va a devolver es el tiempo en segundos que pasaron desde las 00.00 del dia al momento que corro el programa. 
                Luego le sumo 3hs en segundos porque te da el tiempo respecto del GMT(0) y el tiempo local de argetina es GMT (+3)*/
                timep=time(NULL) - time(NULL)%86400 + 10800;    

                for(j=0; j<CANT; j++, timep=timep+10)          //Tomo tantos datos como 10 segundos hay en un dia -->8640
                {
                        //Le voy agregando 10 seg en todas las pasadas
                        tlocal=localtime(&timep);       //Tomo el tiempo local
                        timer=(char *) malloc(sizeof(char) * 20);        //pido memoria para guardar mi string
                        if(timer == NULL)
                        {
                                perror("Error - Al pedir memoria\n");
                                exit(-1);
                        }

                        strftime(timer,20,"%Y%m%d;%H%M%S",tlocal);      //Asigna una direccion a timer donde guarda el string YYYYMMDD;HHMMSS+NULL
                        data.volt= (220 -220 * 0.2) + ( rand() % 89 );          //Devuelve un valor de tension que fluctua un 20% respecto de 220V (220+-44)
                        
                        fprintf(fp, "%d;%s;%d\n", data.zona, timer, data.volt);

                        free(timer);
                }

                fclose(fp);
        }

        return 0;
}