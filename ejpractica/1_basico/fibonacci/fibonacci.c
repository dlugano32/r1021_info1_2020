#include <stdio.h>

void fibonacci(int a);

int main(void)
{
	int n=0, fin=0;
	
	do
	{
		printf("Indique cuantos numeros de la serie de fibonacci quiere representar: ");
		scanf("%d", &n);
		
		if(n>0)
		{
			fibonacci(n);
			fin=1;
		}
		else
		{
			printf("Por favor ingrese un numero mayor a 0\n\n");
		}
		
	}while(fin==0);
	
	return (0);
}


void fibonacci (int n)
{
	int a=0,b=1,c=0;
	
	if (n>1)
	{
		printf("%d %d ",a,b);
	
		for(int i=0; i<(n-2);i++)
		{
			c=a+b;
			printf("%d ", c);
			a=b;
			b=c;
		}
	}
	else
	{ 
		printf("%d",a);
	}
				
	printf("\n");
}
