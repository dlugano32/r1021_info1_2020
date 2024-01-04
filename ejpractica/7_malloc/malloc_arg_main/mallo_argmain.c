#include "ABC.h"

int main (int argc, char **argv)
{
       int i=0, j=0;
       char **vec_s, *p;
       size_t length;

       vec_s=(char**)malloc(sizeof(char *) * (argc-1));
       if(vec_s==NULL)
       {
              printf("ERROR\n");
       }

       for(i=1, j=0; i<argc; i++, j++)
       {
              length=strlen(*(argv+i));
              p=(char*)malloc(sizeof(char) * (length+1));
              strcpy(p, *(argv+i));
              *(vec_s+j)=p;
       }

       ordenABC(vec_s, argc);
       imprimir(vec_s, argc);
       
       for(j=0; j<(argc-1) ; j++)
       {
              free(*(vec_s+j));
       }
       free(vec_s);
       
       return(0);
}