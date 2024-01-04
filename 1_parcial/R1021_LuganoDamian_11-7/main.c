#include "mylib.h"

int main (int argc, char **argv)
{
       int i=0, j=0, num=0, r=0;
       float prom=0;
       int *vec=NULL;
       char *p=NULL;


       vec=(int *) malloc(sizeof(int) * (argc-1) );
       if(vec==NULL)
       {
              printf("ERROR\n");
              r=1;
       }

       for(i=0; i<(argc-1); i++)
       {
              p= *(argv + (1+i));
              for(j=0; *(p+j)!='\0' ; j++)
              {
                     if(*(p+j)>= '0' && *(p + j)<='9')
                     {
                     }
                     else
                     {
                            r=1;
                     }
              }
       }

       if(r==0)
       {
              for(i=0; i<(argc-1) ; i++)
              {      
                     num=atoi( *(argv +(i+1)) );
                     *(vec+i)=num;
              }

              for(i=0, num=0; i<(argc-1); i++) //suma de todos los terminos
              {
                     num=num + *(vec + i);
              }

              printf("Suma de todos los terminos: %d\n", num);

              prom=(float)num/(argc-1); //saco promedio
              printf("Promedio de todos los terminos: %f\n", prom);

              ascendente(vec, argc-1); //lo ordeno ascendentemente

              printf("El mayor es: %d\n", *vec);
              printf("El menor es: %d\n", *(vec + (argc-2) ) ); //argc-1 es la cantidad de numeros, argc -2 es el ultimo numero
       }
       else
       {
              printf("Hay un error con los valores ingresados\n");
       }
       
       free(vec);

       return r;
}      