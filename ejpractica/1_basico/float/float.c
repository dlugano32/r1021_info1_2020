#include <stdio.h>

int main(void)
{
	float num1=0,num2=0;
	float suma=0,resta=0,mult=0,div=0;
	
	printf("Ingrese un numero con coma: ");
	scanf("%f",&num1);
	
	printf("Ingrese otro numero con coma: ");
	scanf("%f",&num2);
	
	suma=num1+num2;
	resta=num1-num2;
	mult=num1*num2;
	
	printf("La suma es: %f\n",suma);
	printf("La resta es: %f\n",resta);
	printf("La multiplicacion es: %f\n",mult);
	if(num2!=0)
	{	
		div=num1/num2;
		printf("La division es: %f\n",div);
	}
	else
	{
		printf("División: No se puede dividir por cero\n");
	}
	
}
