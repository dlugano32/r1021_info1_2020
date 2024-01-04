#include <stdio.h>
#include <stdlib.h>

#define n 6

int main (void)
{
	int aux=0, array[n];
       int k=0, i=0, j=0;
	
	for(k=0; k<n;k++)
		{
			scanf("%d", &array[k]);
		}
		
	for (i = 0; i < n-1 ; i++) 
       {
           for (j = 0; j < n-i-1 ; j++)
              {
                 if (array[j] > array[j+1]) 
                     {
                            aux =  array[j];
                            array[j] = array[j+1];
                            array[j+1] = aux;
                     }
              }
       }
        
       for(int k=0; k<n;k++)	
	{
		printf("Poscion %d: %d\n", k, array[k]);
	}
	
	return (0);
}

/*
 for(i=0;i<N-1;i++) {
    for(j=0;j<N-i-1;j++) {
      if(vec[j]>vec[j+1]) {
        aux=vec[j];
        vec[j]=vec[j+1];
        vec[j+1]=aux;
      }
*/