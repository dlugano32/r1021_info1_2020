#include <stdio.h>
#include <math.h>

int main(void)
{
	int a,b,c;
	int succ=1;
	
	while (succ==1)
	{
		
	printf("Ingrese medidas de 3 lados de un triangulo en cm: \n");
	
	printf("Lado n°1: ");
	scanf("%d", &a);
	
	printf("Lado n°2: ");
	scanf("%d", &b);
	
	printf("Lado n°3: ");
	scanf("%d", &c);
	
	if(a<0 || b<0 || c<0)
	{
		printf("No se permiten numeros negativos por favor ingrese los numeros otra vez\n\n");
	}
	 else if(a>b+c || b>c+a || c>a+b)
	{
		printf("Los lados provistos no forman un triangulo por favor ingrese los numeros otra vez\n\n");
	}
	else 
	{
		succ=0;
	}
	
	} 
	
	if(a==b && b==c)
	{
		printf("El triangulo es equilatero\n");
	}
	else if(a==b || b==c || a==c)
			{
				printf("El triangulo es isosceles\n");
			}
			else 
			{
				printf("El triangulo es escaleno\n");
			}
}
