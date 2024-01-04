/*3) El programa recibe un “mensaje a moderar” por línea de comandos. Ejemplo: $ nombre_programa Hola mundo!! ¿Que tal? donde Hola Mundo!! ¿Que tal? es el mensaje a moderar.

Ni bien se carga en memoria, el programa ejecutará la siguiente secuencia de operaciones:

3.1. Requerirá al usuario el ingreso de hasta 10 palabras prohibidas por teclado. El ingreso finaliza cuando una cadena se compone solo de '\0', 
es decir cuando el usuario pulsó solo ENTER, o cuando se alcanza el valor máximo de 10 palabras. Así armará un arreglo de hasta 10 palabras prohibidas.

3.2. A continuación (es decir, una vez ingresada la lista completa de palabras prohibidas) el programa buscará en el mensaje a moderar, cada una de las palabras 
que componen la black list, y de encontrarla reemplazará cada uno de sus caracteres por una “X”. Considerar que una palabra prohibida puede aparecer más de una 
vez en el mensaje a moderar.

3.3. Una vez completada esta tarea imprimirá por pantalla el “mensaje moderado”, y en la siguiente línea una leyenda que informe la cantidad de caracteres reemplazados por “X”*/

#include "black_list.h"

int main(int argc, char **argv) 
{
       char **black_list, *p, word[N], c;
       int i=0, j=0, k=0, cont_b=0, cont_x=0, fin=0;
       size_t length;

       black_list=(char **)malloc(sizeof(char *));
       if(black_list==NULL)
       {
              printf("ERROR\n");
       }

       do
       {
              fgets(word, N, stdin);
              length=strlen(word);

              p=(char*)malloc(sizeof(char) * length);
              strcpy(p, word);
              *(black_list+i)=p;

              c=*(*(black_list+i));

              if(c!=10) //pregunto si el char es igual a enter
              {
                     black_list=(char**)realloc(black_list ,sizeof(char *) * (i+2));
              }
              else
                     {
                            free(p);
                            *(black_list+i)=NULL;
                     }

              i++;

              if(c ==10 || i ==10)
              {
                     fin=1;
              }
              
       }
       while (fin!=1);
       cont_b=i-1; //le resto 1 porque me cuenta el enter viste

       for(i=1; i<argc; i++)
       {
              p=*(argv+i);
       
              for(j=0; j<cont_b; j++)
              {
                     if( strcmp( p, *(black_list+j))== -10 ) // le pongo -10 porque el de black_list tiene el enter del fgets
                     {
                            for(k=0; *(p+k)!='\0'; k++)
                            {
                                   *(p+k)='X';
                                   cont_x++;
                            }
                     }
              }
       }

       printf("Palabra modificada:\n");
       imprimir(argv+1);
       printf("Cantidad de palabras cambiadas: %d\n", cont_x);

       //printf("\nBlack list\n");
       //imprimir(black_list);
     
       for(j=0; *(black_list+j)!=NULL; j++)
       {
              free(*(black_list+j));
       }

       free(*(black_list+j));
       free(black_list);

       return(0);
}