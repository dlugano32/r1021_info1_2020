#include "mylib.h"

int main (int argc, char **argv)
{
       char **vec=NULL;
       int i=0;

       vec= (char **) malloc(sizeof(char*) * (argc-1));
       if(vec==NULL)
       {
              printf("ERROR\n");
       }

       vocales(argv, vec, argc);
       printf("Solo consonantes:\n");
       for(i=0; i<(argc-1); i++)
       {
              printf("%s\t", *(vec+i));
       }

       consonantes(argv, vec, argc);
       printf("\nSolo vocales:\n");
       for(i=0; i<(argc-1); i++)
       {
              printf("%s\t", *(vec+i));
       }
       printf("\n");

       for(i=0; i<(argc-1); i++)
       {
              free(*(vec +i));
       }

       free(vec);

       return (0);
}