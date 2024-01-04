/*
2) Crear una función que reciba un listado de strings separados por comas y devuelva una estructura con un puntero a un vector de punteros a string 
y un entero indicando la cantidad de strings (archivos) que tiene el vector. El vector (creado por esta función) debe contener una puntero a cada string 
de la cadena. Para la realización de esta función puede utilizar strtok().
*/
#include "my.h"

int main (void)
{
        struct listado data;
        int i=0;
        char str[] ={"arch01.txt,arch02.txt,arch03.txt,arch04.txt,arch05.txt,arch06.txt,arch07.txt"};

        data=function(str);
        
        for(i=0; i<data.cant; i++)
        {
                printf("[%d]= %s\n", i, data.str[i]);
        }

        /*LIBERO MEMORIA*/
        for (i=0; i<data.cant ; i++)
        {
                free(data.str[i]);
        }

        free(data.str);

        return 0;
}

struct listado function ( char *archStr)
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