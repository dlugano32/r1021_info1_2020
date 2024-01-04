#include "my.h"

int main (void)
{
       FILE *fp;
       struct alumno **vec =NULL, *aux;
       int i=0, registros=0;

       vec=(struct alumno **) malloc( sizeof(struct alumno*) );

       do
       {
              printf("Alumno N°%d\n",i+1 );
              aux=(struct alumno *) malloc(sizeof (struct alumno));
              carga(aux); //Cargo la estructura

              if(aux->legajo!=0)
              {
                     *(vec + i)=aux;
                     vec=(struct alumno **) realloc(vec, sizeof(struct alumno*) * (i+2) );
                     i++;
              }
              else
              {
                     free(aux);
              }
              printf("\n");
              
       } while (aux->legajo!=0);

       registros=i; //guardo la cantidad de alumnos
       ordenar_apellido(vec, registros);

       //Imprimo todo en archivo de salida
       fp=fopen("Salida.txt", "w");
       if(fp==NULL)
       {
              printf("ERROR - No se pudo abrir el archivo\n");
       }

       for(i=0; i<registros; i++)
       {
              fprintf(fp,"Legajo:\t%d\nApellido:\t%s\nNombre:\t%s\n\n", vec[i]->legajo, vec[i]->apellido, vec[i]->nombre );
       }

       fclose(fp);

       //Libero memoria

       for(i=0; i<registros; i++)
       {
              free(vec[i]->apellido);
              free(vec[i]->nombre);
       }

       for(i=0; i<registros; i++)
       {
              free(*(vec + i));
       }
       free(vec);

       return 0;
}