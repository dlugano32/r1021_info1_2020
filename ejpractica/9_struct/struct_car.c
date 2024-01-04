#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 2

struct car
{
       char fabricante[20];
       char modelo[20];
       char patente [10];
       int anio;
       int kilometraje;
       float precio;
};

void imprimir_estructura(struct car *autos);

int main (void)
{
       int i=0;
       struct car autos[CANT];

       for(i=0; i<CANT; i++)
       {
              printf("Coche N°%d:\n", i);
              printf("Ingrese fabricante:\n");
              scanf("%s", autos[i].fabricante);
              printf("Ingrese modelo:\n");
              scanf("%s", autos[i].modelo);
              printf("Ingrese patente:\n");
              scanf("%s", autos[i].patente);
              printf("Ingrese año\n");
              scanf("%d", &autos[i].anio);
              printf("Ingrese km\n");
              scanf("%d", &autos[i].kilometraje);
              printf("Ingrese precio:\n");
              scanf("%f", &autos[i].precio);
              printf("\n");
       }

       imprimir_estructura(autos);

       return 0;
}

void imprimir_estructura(struct car *autos)
{
       int i=0;

       for(i=0; i<CANT; i++)
       {
              printf("Coche N°%d:\n", i);
              printf("Fabricante:\n");
              printf("%s\n", autos->fabricante);
              printf("Modelo:\n");
              printf("%s\n", autos->modelo);
              printf("Patente:\n");
              printf("%s\n", autos->patente);
              printf("Ingrese año\n");
              printf("%d\n", autos->anio);
              printf("Km\n");
              printf("%d\n", autos->kilometraje);
              printf("Precio:\n");
              printf("%f\n", autos->precio);
              printf("\n");
              autos++;
       }
}