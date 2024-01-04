#include "11.8.h"

void file_out(char ** archivo, char*str, const char *fin)
{
       char *aux=NULL;
       int i=0;

       for(i=0; *(str+i)!='.'; i++){       }

       aux=(char*)malloc( i * sizeof(char) );
       
       for(i=0; *(str+i)!='.'; i++)
       {
              *(aux+i)=*(str+i);
       }
       *(aux+i)='\0';

       *archivo=(char *) malloc( sizeof(char) * (strlen(aux)+strlen(fin)+1) );
       strcpy(*archivo, aux);
       strcat(*archivo,fin);

       printf("%s\n", *archivo);
       free(aux);
}

void chgcase (FILE *f_in, FILE *f_out, char* choice)
{
       char word[TAM];
       int x=0;

       if(strcmp(choice, "-u") ==0)
       {
              do
              {
                     x=fscanf(f_in,"%s", word);
                     if(x!=EOF)
                     {
                            strupr(word);
                            fprintf(f_out, "%s", word);
                            fprintf(f_out," "); //imprimo un espacio luego de cada palabra
                     }

              }while(x!=EOF);

       }
       else if(strcmp (choice,"-l")==0)
       {
              do
              {
                     x=fscanf(f_in,"%s", word);
                     if(x!=EOF)
                     {
                            strlwr(word);
                            fprintf(f_out, "%s", word);
                            fprintf(f_out," "); //imprimo un espacio luego de cada palabra
                     }
                     
              }while(x!=EOF);

       }
       else
       {
              printf("ERROR - Argumento ingresado incorrecto\n");
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

void strupr(char *str)
{
       int i=0;

       for(i=0; *(str + i)!='\0'; i++)
       {
              if(*(str + i)>='a' && *(str + i)<='z')
              {
                     *(str + i)= *(str + i) - ' ';
              }
       }
}