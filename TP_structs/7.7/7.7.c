#include "7.7_lib.h"

int main (void)
{
       FILE *fp;
       struct datos **vec, *ptr;
       int i=0, cant=0;

       vec=(struct datos  **) malloc( sizeof(struct datos *) );

       do
       {
              ptr=(struct datos *) malloc(sizeof (struct datos));
              printf("Alumno N°%d\n", i+1);
              carga(ptr);

              if( fin (ptr) == 0  )
              {
                     vec[i]=ptr;
                     vec=(struct datos **) realloc(vec, (i+2) * sizeof(struct datos *) );
                     i++;
              }
              else
              {
                     free(ptr);
              }
              printf("\n");

       } while ( fin (ptr) == 0 );

       cant = i;       // cant=cantidad de alumnos cargados
       ordenar_apellido(vec, cant);

       fp=fopen("legajos.dbf", "w");
       if(fp ==NULL)
       {
              printf("ERROR - No se pudo abrir el archivo\n");
              return -1;
       }
       
       for(i=0; i<cant; i++) //Cargo los datos en el archivo de salida
       {
              fwrite( *(vec + i), sizeof(struct datos), 1, fp);
       }

       fclose(fp);

       for(i=0; i<cant; i++)
       {
              free( *(vec + i) );
       }
       free(vec);

       return 0;
}