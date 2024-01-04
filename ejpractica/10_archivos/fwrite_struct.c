#include <stdio.h>
#include <string.h>

#define N 5 //CANTIDAD DE ALUMNOS
#define TAM 20

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
      FILE *fp, *fp2;

      fp=fopen("out.dat", "w");
      if(fp==NULL)
      {
             printf("No se pudo abrir el archivo\n");
      }

      fp2=fopen("out.txt", "w");
       if(fp2==NULL)
      {
             printf("No se pudo abrir el archivo\n");
      }

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

              fprintf(fp2, "Nombre :%sApellido: %sNota: %d\n\n", alumnos[i].nombre, alumnos[i].apellido, alumnos[i].nota);
       }

       fwrite(&alumnos, sizeof(struct primer_parcial), N, fp );
       
       fclose(fp);
       fclose(fp2);
       return 0;
}