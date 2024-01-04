#include "my.h"

int main(void)
{
        int fd=0;
        int  j=0, k=0, l=0;
        int length =22; //El largo del str por dato es 21 + '\0' =22
        char *str=NULL, s_temp[6];
        struct Nodo aux;
        struct cola dato;

        cola_init(&dato);

        fd=open("/sys/class/sensor/value", O_RDONLY);         //Abro el archivo con el path
        if(fd < 0)
        {
                printf("Error - Al abrir el archivo");
                return -1;
        }

        while(1)                //Va a tomar datos constantemente
        {
                if( read(fd, str, length) < 0 )         //El programa se queda bloqueado mientras no reciba datos
                {
                        printf("Error - Al leer el archivo\n");
                        return -1;
                }

                for(j=0, k=0, l=0; *(str + j) != '\0' ; j++)
                {
                        if(j<4)
                        {
                                *(s_temp+j)=*(str + j);         //los primeros 5 bits son de temperatura
                        }
                        else if(j>4 && j< 12)           //los 8 bits siguientes son de la fecha
                        {
                                aux.fecha[k]= *(str + j);
                                k++;
                        }
                        else if( j < 12)        //Los bits siguientes son de la hora
                        {
                                aux.hora[l]= *(str + j);
                                l++;
                        }
                }
                s_temp[5]='\0'; //Le pongo un NULL al final de la 
                aux.temp=atof(s_temp);

                push( &dato, aux);

                if(dato.flag_lleno == si)
                {
                        printf("La cola Circular está llena\n");
                }

        }

        return 0;
}