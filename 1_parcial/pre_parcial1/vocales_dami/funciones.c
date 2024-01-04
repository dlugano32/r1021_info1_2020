#include "mylib.h"

void vocales(char **argv, char**vec, int cant)
{
       char *q=NULL, *p=NULL;
       int i=0, j=0, k=0, l=0, length;

       for(i=1, k=0, q=NULL; i < cant ; i++, k++)
       {
              p=*(argv+ i);
              strlwr(p); //paso todo a minuscula para no tener errores
              length= (int) strlen(*( argv+i));
              q= (char *) malloc( (length +1 ) * sizeof(char) ); //malloc de la palabra actual (solo consonantes)
              
              for(j=0, l=0; *(p +j)!= '\0' ; j++)
              {
                     if(*(p+j)=='a' || *(p+j)=='e' || *(p+j)=='i' || *(p+j)=='o' || *(p+j)=='u')
                     {
                            length--; 
                            q= (char *) realloc (q,  (length+1) *sizeof(char));      //hago realloc porque va a haber una consonante que no voy a tener en cuenta //el +1 es para el NULL
                     }
                     else
                     {
                            *(q+l)=*(p+j); //guardo en el malloc de solo consontantes la consonante correspondiente
                            l++;
                     }
              }

              *(vec + k)=q; //una vez que tengo la direccion final la guardo en el vector de direcciones
       }
}

void consonantes(char **argv, char**vec, int cant)
{
       char *q=NULL, *p=NULL;
       int i=0, j=0, k=0, l=0, length;

       for(i=1, k=0, q=NULL; i < cant ; i++, k++)
       {
              p=*(argv+ i);
              strlwr(p); //paso todo a minuscula para no tener errores
              length= (int) strlen(*( argv+i));
              q= (char *) malloc( (length +1 ) * sizeof(char) ); //malloc de la palabra actual (solo vocales)
              
              for(j=0, l=0; *(p +j)!= '\0' ; j++)
              {
                     if(*(p+j)!='a' && *(p+j)!='e' && *(p+j)!='i' && *(p+j)!='o' && *(p+j)!='u')
                     {
                            length--; 
                            q= (char *) realloc (q,  (length+1) *sizeof(char));      //hago realloc porque va a haber una vocal que no voy a tener en cuenta //el +1 es para el NULL
                     }
                     else
                     {
                            *(q+l)=*(p+j); //guardo en el malloc de solo consontantes la consonante correspondiente
                            l++;
                     }
              }

              *(vec + k)=q; //una vez que tengo la direccion final la guardo en el vector de direcciones
       }
}

void strlwr (char *str)
{
       int i=0;

       for(i=0; *(str + i)!='\0'; i++)
       {
              if(*(str + i)>='A' && *(str + i)<='Z')
              {
                     *(str + i)= *(str + i)+ ' ';
              }
       }
}