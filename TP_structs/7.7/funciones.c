#include "7.7_lib.h"

void carga(struct datos * alumno)
{
       struct datos aux;

       printf("Ingrese numero de legajo:\t");
       scanf("%ld", &aux.legajo);
       alumno->legajo=aux.legajo;

       if(aux.legajo!=0)
       {
              printf("Ingrese el apellido del alumno:\t");
              setbuf(stdin,NULL);
              fgets(aux.apellido, TAM_S, stdin);
              printf("Ingrese el nombre del alumno:\t");
              setbuf(stdin,NULL);
              fgets(aux.nombre, TAM_S, stdin);

              strcpy(alumno->apellido,aux.apellido);
              strcpy(alumno->nombre,aux.nombre);
       }
}      
       
int fin(struct datos * alumno)
{      
       if(alumno->legajo==0)
       {
              return 1;
       }
       else
       {
              return 0;
       }
}

void ordenar_apellido(struct datos ** vec, int cant)
{
       int i=0, j=0;
       struct datos *aux;

       for (i = 0; i < (cant-1) ; i++) 
       {
           for (j = 0; j < (cant-i-1) ; j++)
              {
                 if (  strcmp( vec[j]->apellido, vec[j+1]->apellido) > 0 ) 
                     {
                            aux =  vec[j];
                            vec[j] = vec[j+1];
                            vec[j+1] = aux;
                     }
              }
       }
}
