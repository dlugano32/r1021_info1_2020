#include <stdio.h>

#define n 6

int main (void)
{
	int mayor=-32000, menor=32000, array[n];
	
	for(int k=0; k<n;k++)
		{
			scanf("%d", &array[k]);
		}
		
	 for (int i = 0; i < n; ++i) 
       {
          
			if(mayor<array[i])
			{
				mayor=array[i];
			}
			else if(menor>array[i])
			{
				menor=array[i];
			}
    
       }
       
	printf("El mayor es: %d\n", mayor);
	printf("El menor es: %d\n", menor);
	
	return (0);
}

