#include "my.h"

int main (int argc, char** argv)
{
        FILE *fd, *fd1;
        int length=0, registros=0, i=0, j=0;
        char * fileName=NULL;
        struct Nodo **vector=NULL, *aux=NULL;

        if(argc != 2)
        {
                printf("Invocar como ./main <file.txt>\n");
                return -1;
        }

        fd=fopen( *(argv +1) , "r");
        if( fd==NULL )
        {
                printf("Error - Al abrir el archivo");
        }

        fseek(fd, 0, SEEK_END);
        length=ftell(fd);
        rewind(fd);
        registros=length/ (sizeof(struct Nodo));       //Cantidad de registros en total
        
        vector=(struct Nodo **) malloc( sizeof(struct Nodo *) * registros);     //Vector de registros

        for(i=0; i<registros; i++)
        {
                vector[i]= (struct Nodo *) malloc (sizeof( struct Nodo ));

                fread(vector[i], sizeof(struct Nodo), 1, fd);

        }

       for(i=0; i<registros-1 ; i++)
       {
              for(j=0; j< (registros -i -1); j++ )
              {
                     if ( vector[j]->temp > vector[j+1]->temp ) 
                     {
                            aux = vector[j];
                            vector[j] = vector[j+1];
                            vector[j+1] = aux;
		       }
              }
       }

       for(i=0; i<registros; i++)
       {
               printf("Temp N°%d = %0.2f\nFecha N%d = %s\n", i+1, vector[i]->temp, i+1, vector[i]->fecha);
       }

        file_out(&fileName, *(argv +1), "-out.txt");

        fd1=fopen(fileName, "w");
        if(fd1==NULL)
        {
                printf("Error - Al abrir el archivo'n");
        }

        for(i=0; i<registros; i++)
        {
                fwrite(vector[i], sizeof(struct Nodo), 1, fd1);
        }

       for(i=0; i<registros; i++)
       {
               free(*(vector +i));
       }

        free(fileName);
        free(vector);
        fclose(fd1);
       fclose(fd);

        return 0;
}