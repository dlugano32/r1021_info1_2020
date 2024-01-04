#include <stdio.h>
#include <math.h>

#define pi 3.141592

float circle(float radio);

int main (void)
{
	float radio;
	
	printf("Ingrese el radio de un numero y se le devolvera su superficie\n");
	scanf("%f", &radio);
	
	printf("Superficie del circulo: %0.4f\n", circle(radio));
	
	return(0);
}

float circle (float radio)
{
	float superficie= pi*pow(radio,2);
	return superficie;
}
