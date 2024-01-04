#include <stdio.h>

int main(void)
{
	int num=0, fact=1;
	printf("Ingrese un numero y se devolvera el factorial: ");
	scanf("%d",&num);
	
	for(int i=1;i<num;i++)
	{
		fact=fact*(i+1);
	}
	printf("El factorial es: %d\n",fact);
}
