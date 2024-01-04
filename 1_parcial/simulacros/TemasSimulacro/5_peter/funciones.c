/*Prototipo de la funcion:
char **extraer_palabras(char *str);
Parametros de entrada:
char *str: Puntero a char, que apunta al string a analizar.
Retorno:
char **: Puntero a puntero a char, que apunta al primer elemento de un vector
de punteros a char. En el vector de punteros a char, cada elemento apunta a un
string que contiene una palabra. El ultimo elemento del vector sera el puntero nulo
(NULL), quedando de largo palabras+1.
Las palabras podran contener letras mayusculas y minusculas.
Utilizar memoria dinamica para la salida.*/

#include "mylib.h"

char **extraer_palabras(char *str)
{
       int i=0, flag=0;
       char **vec=NULL, *p=NULL, *word=NULL;

       vec= (char **) malloc(sizeof(char*));

       for(i=0; *(str+i)!='\0' ; i++)
       {
              if(*(str+i)==' ')
              {
                     flag++;
              }
       }

       if(flag>0)
       {
              word=strtok(str," ");
              p= (char*) malloc(sizeof(char) + (strlen(word)+1) );
              strcpy(p, word);
              *vec=p;

              for(i=1; i<(flag+1) ; i++) //flag es la cantidad de espacios (cantidad de letras -1) pero empiezo el for con i=1
              {
                     vec=(char **)realloc(vec, sizeof(char*) * (i+1) );
                     word=strtok(NULL," ");
                     p= (char*) malloc(sizeof(char) + (strlen(word)+1) );
                     strcpy(p, word);
                     *(vec+i)=p;
              }
              
              printf("Cantidad de palabras %d\n", i);

              vec=(char **)realloc(vec, sizeof(char*) * (i+1) );
              *(vec+i)='\0';

       }
       else
       {
              printf("Es solo una palabra\n");
              p= (char*) malloc(sizeof(char)* (strlen(str) + 1) );
              strcpy(p , str);
              *vec=p;

              vec=(char **)realloc(vec, sizeof(char*) * 2 );
              *(vec + 1 )='\0';
       }
       
       return(vec);
}

void imprimir_palabras(char **vec)
{
       int i=0;

       for(i=0; *(vec + i)!=NULL; i++)
       {
              printf("%s\n", *(vec + i) );
       }
}

void liberar_memoria(char **vec)
{
       int i=0;

       for(i=0; *(vec + i)!=NULL; i++)
       {
              free ( *(vec + i) );
       }
       free (*(vec+ i)); //libero el NULL

       free(vec);
}