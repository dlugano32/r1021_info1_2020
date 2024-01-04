#include "Rot.h"

int main(void)
{
       char dataPtr[TAM], * dataPtrCodificada ;
       int devuelve ,longitud ,i;

       printf("Ingrese texto a codificar\n");
       fgets(dataPtr ,TAM ,stdin);
       longitud = strlen(dataPtr);
       for (i=0; dataPtr[i]!= '\0' ;i++){ }
       dataPtr[i -1]= '\0';
       dataPtrCodificada = (char *) malloc ( longitud * sizeof(char));
       devuelve = rot_13( dataPtr , dataPtrCodificada);
       if (devuelve == -1)
       {
              printf("el mensaje contiene un caracter distinto de una letra o un espacio\n");
       }
       else
       {
              printf("el mensaje %s fue codificado a %s\n" , dataPtr, dataPtrCodificada);
              printf("la cantidad intercambiada fue de: %d\r\n" ,devuelve);
       }

       free (dataPtrCodificada);

       return (0);
}