#include <stdio.h>

int main(void)
{	
	int num;
	
	printf("Ingrese un numero cualquiera: ");
	scanf("%d",&num);
	
	if(num%2==0)
	{
		printf("%d es par.\n",num);
	}
	else 
	{
		printf("%d es impar.\n",num);
	}
	
	
}
