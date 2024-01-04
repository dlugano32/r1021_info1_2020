#include "my.h"

int main (int argc, char **argv)
{
       if(argc ==2)
       {
              FILE *fp;
              int registros=0, i=0;
              struct mediciones **vec;

              fp=fopen(*(argv+1), "r");
              if(fp==NULL)
              {
                     printf("ERROR - No se pudo abrir el archivo\n");
                     return -1;
              }

              fseek(fp, 0, SEEK_END);
              registros= ftell(fp) / sizeof(struct mediciones);
              rewind(fp);

              vec=(struct mediciones **) malloc( sizeof( struct mediciones *) * registros );

              save_struct(fp, vec , registros);

              for(i=0; i<registros; i++)
              {
                     printf("%d\t%d\t%0.2f%s\n", vec[i]->time, vec[i]->id, vec[i]->valor, vec[i]->unidad );
              }

              for(i=0; i<registros; i++)
              {
                     free(*(vec + i));
              }
              
              free(vec);

              fclose(fp);
       }
       else
       {
              printf("ERROR - Cantidad de argumentos incorrecta\n");
              return -1;
       }

       return 0;
}
