#include "mylib.h"

int ObtenerMayores(int *vec, int n, int umbral)
{
       int i=0,cant=0;

       for(i=0; i<n; i++)
       {
              if( *(vec +i)>umbral )
              {
                     cant++;
              }
       }
       
       return cant;
}