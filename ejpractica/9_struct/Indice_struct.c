#include <stdio.h>
#include <string.h>

#define N 2 //CANTIDAD DE ALUMNOS
#define TAM 20

struct primer_parcial
{
       char nombre[TAM];
       char apellido[TAM];
       int nota;
};

int main (void)
{
       int i=0, j=0;
      struct primer_parcial alumnos[N], *Indice[N], *aux=NULL;

       for(i=0; i<N; i++)
       {
              printf("Ingrese nombre: ");
              fgets(alumnos[i].nombre, TAM, stdin);
              setbuf(stdin, NULL);
              printf("Ingrese apellido: ");
              fgets(alumnos[i].apellido, TAM, stdin);
              setbuf(stdin, NULL);
              printf("Ingrese nota: ");
              scanf("%d", &alumnos[i].nota);
              setbuf(stdin, NULL);
              printf("\n");
              Indice[i]=&(alumnos[i]);
       }

       for(i=0; i<N-1 ; i++)
       {
              for(j=0; j< (N -i -1); j++ )
              {
                     if ( strcmp(Indice[j]->apellido, Indice[j+1]->apellido ) > 0 ) 
                     {
                            aux = Indice[j];
                            Indice[j] = Indice[j+1];
                            Indice[j+1] = aux;
		       }
              }
       }

       printf("\nEn orden: \n");
       for(i=0; i<N; i++)
       {
              printf("%s", Indice[i]->apellido);
       }
       
       printf("\nSin orden: \n");
       for(i=0; i<N; i++)
       {
              printf("%s", alumnos[i].apellido);
       }

       return 0;
}