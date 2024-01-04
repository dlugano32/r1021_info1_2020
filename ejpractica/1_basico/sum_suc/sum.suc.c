#include <stdio.h>

int main (void)
{
	int a,b,c=0;
	scanf("%d",&a);
	scanf("%d",&b);
	
	if (b>a)
	{
		for(int i=1; i<(b-a);i++)
		{
			c=c+(a+i);
		}
		printf("El resultado es %d \n",c);
	}
	else
	{
		printf("a tiene que ser menor que b\n");
	}
	return (0);
}
