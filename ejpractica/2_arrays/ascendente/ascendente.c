#include <stdio.h>

#define n 6

int main (void)
{
	int aux=0, array[n];
	
	for(int k=0; k<n;k++)
		{
			scanf("%d", &array[k]);
		}
		
	 for (int i = 0; i < n; ++i) 
       {
           for (int j = i + 1; j < n; ++j)
           {
               if (array[i] > array[j]) 
               {
                   aux =  array[i];
                   array[i] = array[j];
                   array[j] = aux;
				}
           }
       }
        
		for(int k=0; k<n;k++)	
		{
			printf("Poscion %d: %d\n", k, array[k]);
		}
	
	return (0);
}
