#include "lib.h"

int main(int argc, char **argv)
{
       int i, j, k;
       char llave;

       char (*func[2])(char)={voc, con};

       char **salida=NULL;
       char *aux;

       printf("Ingrese opción:\n[0] copio vocales.\n[1] copio consonantes.\n");
       scanf("%c", &llave);

       for(i=1; i<argc; i++)
       {
              aux=NULL;
              salida=(char **) realloc(salida, i*sizeof(char *));
              
              for(j=0, k=0; *(*(argv+i)+j)!='\0'; j++)
              {
                     if(func[(int) (llave-48)](*(*(argv+i)+j)))
                     {
                            k++;
                            aux=(char *) realloc(aux, k*sizeof(char));
                            *(aux+k-1)=*(*(argv+i)+j);
                     }
              }
              aux=(char *) realloc(aux, (k+1)*sizeof(char));
              *(aux+k)='\0';
              *(salida+i-1)=aux;
       }

       for(j=0; j<(i-1); j++)
       {
              printf("%s ", *(salida+j));
              free(*(salida+j));
       }
       printf("\n");
       free(salida);

       return 0;
}
