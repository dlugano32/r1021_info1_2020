#include "mylib.h"

int main(void)
{
       char c, str[TAM], *p=NULL, **vec=NULL;
       int i=0, j=0, length=0, lin=0, flag=0, car=0, word=0;

       vec=(char**) malloc(sizeof(char*));
       if(vec==NULL)
	{
		printf("ERROR ASIGNANDO MEMORIA\n");
	}

       do
       {
              fgets(str, TAM, stdin);
              length=my_strlen(str);

              p= (char*) malloc(sizeof(char) * (length+1) );
              if(p==NULL)
	       {
		       printf("ERROR ASIGNANDO MEMORIA\n");
	       }
              my_strcpy(p, str);
              *(vec+i)=p;
              c=*p; //guardo el primer caracter del string en c

              if (c != '.')
              {
                    vec=(char **) realloc(vec, sizeof(char*) * (2+i)); //reservo memoria para el proximo string
                     if(vec==NULL)
	              {
	              	printf("ERROR ASIGNANDO MEMORIA\n");
                     }
              }
              else
                     {
                            free(p);
                            *(vec+i)='\0';
                     }

              i++;
       }
       while (c !='.');

       
       for(i=0; *(vec +i)!=NULL; i++)
       {
              p=*(vec+i);
              word++; //por el hecho de haber una columna hay una palabra

              for(j=0; *(p+j)!='\0'; j++)
              {
                     if(*(p+j)== '\n')
                     {
                            lin++;
                     }

                     if(*(p+j)== ' ' || *(p+j)== '\t')
                     {
                            flag++;
                            if(flag==1)
                            {
                                   word++;
                            }
                     }
                     else
                     {
                            flag=0;

                            if(*(p+j)!='\n')
                            {
                                   car++;
                            }
                     }
              }
       }

       printf("Cantidad de lineas: %d\n", lin );
       printf("Cantidad de palabras: %d\n", word);//en dos palabras hay un espacio
       printf("Cantidad de caracteres: %d\n", car);
       liberar_memoria(vec);

       return 0;
}