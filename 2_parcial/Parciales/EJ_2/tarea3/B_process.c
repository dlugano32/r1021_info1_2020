#include "my.h"

int main(void)
{
        int fifo_recv=0, fifo_send=0, length=0, i=0;
        char buffer[TAM], msg[]={"Palabra no encontrada"}, *str=NULL, *p=NULL, *sin=NULL;
        FILE *fp=NULL;
        
        fp=fopen("sinonimos.txt", "r");
        if( fp==NULL)
        {
                printf("Error - No se pudo abrir el archivo\n");
                return -1;
        }

        fseek(fp, 0, SEEK_END);
        length=ftell(fp);
        rewind(fp);
        str=(char *) malloc( sizeof(char) *length );
        if(str==NULL)
        {
                printf("Error - Al pedir memoria");
                return -1;
        }

        fread(str, length, 1, fp);      //Leo todo el file

        fifo_recv=open("fifo_1", O_RDONLY);
        if( fifo_recv < 0)
        {
                perror("Error - Al recibir ");
                return -1;
        }

        memset(buffer, 0, TAM);
        if(read(fifo_recv, buffer, TAM) < 0)
        {
                perror("Error - Al leer la fifo\t");
                return -1;
        }

        printf("Palabra recibida ->%s\n", buffer);


        p=strstr(str, buffer);          //Busco en el haystack str el needle buffer
        if(p==NULL)
        {
                fifo_send=open("fifo_2", O_WRONLY);
                if(fifo_send < 0)
                {
                        perror("Error - Al abrir la fifo\t");
                        return -1;
                }

                if( write(fifo_send, msg, strlen(msg)) <0)
                {
                        perror("Error - Al escribir en la fifo\t");
                        return -1;
                }
        }
        else
        {
                for(i=0; *(p+i) !=':' ; i++){ }   //pongo el puntero en ':'
                p=(p+i)+1;    //Le sumo uno para llegar al sinonimo

                sin=(char *) malloc(sizeof(char));

                for(i=0; *(p+i)!='\n' && *(p+i)!='\0'; i++)
                {
                        *(sin + i)=*(p+i);
                        sin=(char *) realloc(sin, sizeof(char) * (i+2) );
                        if(sin ==NULL)
                        {
                                perror("Error - Al reasignar memoria\t");
                                return -1;
                        }
                }
                *(sin +i)='\0';

                printf("sinonimo=%s\n", sin);
                
                fifo_send=open("fifo_2", O_WRONLY);
                if(fifo_send < 0)
                {
                        perror("Error - Al abrir la fifo\t");
                        return -1;
                }

                if( write(fifo_send, sin, strlen(sin)) <0)
                {
                        perror("Error - Al escribir en la fifo\t");
                        return -1;
                }

                free(sin);
        }

        close(fifo_recv);
        close(fifo_send);
        fclose(fp);
        free(str);
        return 0;
}