#include "mylib.h"

void promedio(int ** matriz, int n, float * res)
{
       int i=0, x=0, y=0;

       for(i=0; i<n; i++)
       {
              x=x+matriz[i][0];
              y=y+matriz[i][1];
       }
       res[0]= (float) x/n;
       res[1]= (float) y/n;
}