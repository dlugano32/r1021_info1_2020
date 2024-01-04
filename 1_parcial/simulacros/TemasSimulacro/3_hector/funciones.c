#include "mylib.h"

void caracteres(char* word)
{
       int i=0;
       for (i=0; *(word + i)!='\0'; i++)
       {
       }
       printf("Cantidad de caracteres: %d\n", i);
}

void vocales(char *word)
{
       int i=0, voc=0;

       for (i=0; *(word + i)!='\0'; i++)
       {
              if(*(word + i)=='a' || *(word + i)=='e' || *(word + i)=='i' || *(word + i)=='o' || *(word + i)=='u' ||
                 *(word + i)=='A' || *(word + i)=='E' || *(word + i)=='I' || *(word + i)=='O' || *(word + i)=='U')
                 {
                        voc++;
                 }
       }

       printf("Cantidad de vocales: %d\n", voc);
       
}      
void consonantes(char *word)
{
       int i=0, cons=0;

       for (i=0; *(word + i)!='\0'; i++)
       {
              if(*(word + i)!='a' && *(word + i)!='e' && *(word + i)!='i' && *(word + i)!='o' && *(word + i)!='u' &&
                 *(word + i)!='A' && *(word + i)!='E' && *(word + i)!='I' && *(word + i)!='O' && *(word + i)!='U')
                 {
                        cons++;
                 }
       }

       printf("Cantidad de consonantes: %d\n", cons);
}