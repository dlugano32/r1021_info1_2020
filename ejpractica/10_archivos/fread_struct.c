#include <stdio.h>

#define TAM 20
#define N 5 

struct primer_parcial
{
       char nombre[TAM];
       char apellido[TAM];
       int nota;
};

int main (void)
{
       int i=0;
       struct primer_parcial alumnos[N];
       FILE *fp;

       fp=fopen("out.dat", "r");
      if(fp==NULL)
      {
             printf("No se pudo abrir el archivo\n");
      }
       

       fread(&alumnos, sizeof(struct primer_parcial), N, fp);
       
       for(i=0; i<N; i++)
       {
              printf("Nombre: %sApellido: %sNota: %d\n", alumnos[i].nombre, alumnos[i].apellido, alumnos[i].nota);
       }
       
       fclose(fp);
       return 0;
}