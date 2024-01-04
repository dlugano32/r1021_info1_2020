/*5. Escribir un programa que tome por línea de comando la cantidad de enteros que va a pedirle al usuario. 
El programa deberá reservar la memoria necesaria para guardarlos y luego pedirle al usuario que ingrese estos enteros de a uno. 
Una vez finalizado el ingreso el programa calculará el valor medio de los enteros ingresados y lo presentará por pantalla.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
       int cant=0, i=0, *p=NULL;
       float prom=0;

       printf("Ingrese la cantidad de enteros que quiere guardar\n");
       scanf("%d", &cant);

       p= (int *) malloc(sizeof(int) * cant);

       printf("Ingrese los numeros que quiere guardar\n");

       for(i=0; i<cant; i++)
       {
              scanf("%d", &(*(p+i)) );
       }

       for(i=0; i<cant; i++)
       {
              prom=prom+ *(p+i);
       }

       prom=prom/cant; //saco promedio de todos los numeros que tengo

       printf("El promedio  es: %0.2f\n", prom);

       return 0;
}