#include "my.h"

void carga(struct alumno *ptr)
{
       char name[TAM];
       int length=0;

       printf("Ingrese el numero de legajo del alumno:\t");
       scanf("%d", &ptr->legajo);
       setbuf(stdin, NULL);

       if(ptr->legajo!=0)
       {
              /*Ingreso apellido de forma dinamica*/
              printf("Ingrese el apellido del alumno:\t");
              fgets(name, TAM, stdin);
              setbuf(stdin, NULL);
              length=strlen(name);

              length --;
              *(name + length)='\0'; //Le saco el enter

              ptr->apellido=(char *) malloc(sizeof (char) * (length+1) );
              strcpy(ptr->apellido , name);

              /*Ingreso nombre de forma dinamica*/
              printf("Ingrese el nombre del alumno:\t");
              fgets(name, TAM, stdin);
              setbuf(stdin, NULL);
              length=strlen(name);

              length --;
              *(name + length)='\0'; //Le saco el enter

              ptr->nombre=(char *) malloc(sizeof (char) * (length+1) );
              strcpy(ptr->nombre , name);
       }
}

void ordenar_apellido(struct alumno ** vec, int cant)
{
       int i=0, j=0;
       struct alumno *aux;

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