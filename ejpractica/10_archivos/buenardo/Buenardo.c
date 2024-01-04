#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
       FILE *f_in, *f_out;

       char s[20], *s_ptr=NULL;
       int length=0, x=0;

       if(argc==2)
       {
              f_in=fopen(*(argv+1), "r");
              f_out=fopen("buenardo.txt", "w");

              do
              {
                     x=fscanf(f_in, "%s", s);

                     if(x!=EOF)
                     {
                            length=strlen(s);
              
                            if( length > (sizeof (char) *2) )
                            {
                                   s_ptr= (char *) malloc( (length +4 + 1) * sizeof(char)); // +4 por el ardo
                                   strcpy(s_ptr, s );
                                   strcat(s_ptr,"ardo");

                                   fprintf(f_out,"%s\n", s_ptr);

                                   free(s_ptr);
                            }
                            else
                            {
                                   fprintf(f_out,"%s\n", s);
                            }
                     }
                            
              }while( x != EOF);

              fclose(f_in);
              fclose(f_out);
       }
       else
       {
              printf("Cantidadardos de argumentardos incorrectardos\n");
       }

       return 0;
}