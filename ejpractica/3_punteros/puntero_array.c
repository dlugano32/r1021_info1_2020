#include <stdio.h>

void ordenAscendente(int *, int);

int main (void)
{
	int n=6;
	int array[n];
	
	for(int i=0; i<n;i++)
		{
			scanf("%d", &array[i]);
		}
	
	ordenAscendente(array,n);
	
	for(int j=0; j<n;j++)	
		{
			printf("Posicion %d: %d\n", j, array[j]);
		}
		
	return (0);
}

void ordenAscendente(int *array, int n)
{
	int aux=0;
	
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
}
