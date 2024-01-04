#include <stdio.h>

int main(void)
{
	int polinomio[4], aux=0;
	
	for(int i=0; i<5; i++)
	{
		scanf("%d", &polinomio[i]);
	}
	
	for(int j=0; j<5; j++)
	{
		for (int k = j + 1; k < 5; ++k)
           {
                   aux =  polinomio[j];
                   polinomio[j] = polinomio[k];
                   polinomio[k] = aux;
           }
	}
	
	for(int x=0; x<5; x++)
	{
		printf("%d\n", polinomio[x]);
	}
	
	
	return(0);
}
