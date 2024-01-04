#include "my.h"

int main(void)
{
        FILE *fd=NULL, *fd1=NULL;
        int length=0, cant=0, i=0, j=0, k=0, l=0, m=0;
        char *str=NULL, s_temp[6];
        struct Nodo **vector, *aux;

        fd=fopen("/mnt/c/info1/in.txt", "r");
        if(fd==NULL)
        {
                printf("Error - Al abrir el archivo\n");
                return -1;
        }

        fd1=fopen("out.txt", "w");
        if(fd1==NULL)
        {
                printf("Error - Al abrir el archivo\n");
                return -1;
        }

        fseek(fd, 0, SEEK_END);
        length=ftell(fd);   //Le saco el EOF
        rewind(fd);
        cant=length/(sizeof(char)*21);          //21 es el largo del string
        
        str=(char *) malloc(sizeof(char) * length );
        if(str==NULL)
        {
                printf("Error - Al asignar memoria\n");
                return -1;
        }

        vector=(struct Nodo **) malloc( sizeof(struct Nodo* ) * cant );
        if(vector==NULL)
        {
                printf("Error - Al asignar memoria\n");
                return -1;
        }

        if( fread(str, length, 1, fd) < 0 )
        {
                printf("Error - Al leer el archivo\n");
                return -1;
        }

        for( i=0, j=0; i<cant; i++ )
        {
                aux=(struct Nodo *) malloc(sizeof(struct Nodo));
                for(m=0, k=0, l=0; m<21; j++,m++)
                {
                        if(m <= 4)
                        {
                                *(s_temp+m)=*(str + j);
                        }
                        else if(m >= 5 && m  <= 12)
                        {
                                aux->hora[k]= *(str + j);
                                k++;
                        }
                        else if( m >= 13 )
                        {
                                aux->fecha[l]= *(str + j);
                                l++;
                        }
                }
                s_temp[5]='\0';
                aux->hora[k]='\0';
                aux->fecha[l]='\0';
                aux->temp=atof(s_temp);
                *(vector + i)=aux;
        }

        for(i=0; i<cant; i++)
        {
                printf("Value N°%d\nTemp= %f\nHora= %s\nFecha= %s\n", i+1, vector[i]->temp, vector[i]->hora, vector[i]->fecha);
                fwrite(vector[i], sizeof(struct Nodo), 1, fd1);
        }

        for(i=0; i<cant; i++)
        {
                free(*(vector + i));
        }
        free(vector);
        free(str);
        fclose(fd);

        return 0;
}