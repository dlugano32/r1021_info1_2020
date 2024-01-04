#include "mylib.h"

int main (void)
{
       char c, word[TAM];
       int i=0, *vec_r=NULL;

       vec_r=(int *)malloc(sizeof(int));
       printf("Ingrese string\n");
       fgets(word, TAM, stdin);
       printf("Ingrese caracter a evaluar\n");
       setbuf(stdin, NULL);
       scanf("%c", &c);
       printf("La cantidad de veces que se repitio %c : %d\n", c, CuantasVeces(word, c, vec_r) );

       for(i=0; *(vec_r + i)!='\0'; i++)
       {
              printf("%d\n",*(vec_r+i) );
       }

       free(vec_r);

       return 0;
}