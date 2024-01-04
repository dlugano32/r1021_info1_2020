#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
       char word_s [20] , word_f[20], c;
       size_t len_s, len_f;
       int i=0;

       fgets(word_f,20,stdin);
       scanf("%s", word_s);

       len_f=strlen(word_f);
       len_s=strlen(word_s);

       printf("Con fgets:\t");
       for(i=0; i<len_f; i++)
       {
              c=word_f[i];
              printf("0x%x\t",c);
       }
       printf("\n");

       printf("Con scanf:\t");
        for(i=0; i<len_s; i++)
       {
              c=word_s[i];
              printf("0x%x\t",c);
       }
       printf("\n");


       printf("Con fgets: %ld\n", len_f );
       
       printf("Con scanf: %ld\n", len_s );


       word_f[len_f-1]='\0';
       len_f--;
       printf("Luego del proceso");
              printf("Con fgets:\t");
       for(i=0; i<len_f; i++)
       {
              c=word_f[i];
              printf("0x%x\t",c);
       }
       printf("\n");
       printf("Con fgets: %ld\n", len_f );

       return(0);
}