#include <stdio.h>
#include <math.h>

int main (void)
{
	float a,b,c,x1=0,x2=0,raiz=0, x_real=0, x1_imag=0, x2_imag=0;
	
	printf("Ingrese los valores a,b y c de una funcion cuadrática.\na: ");
	scanf("%f", &a);
	printf("b: ");
	scanf("%f", &b);
	printf("c: ");
	scanf("%f", &c);
	
	raiz=(pow(b,2)-4*a*c); //uso el valor de la raiz para discriminar si tiene raices reales o imaginarias

	if (a==0)
	{
		printf("No es una funcion de segundo grado.\n");
		
	}
	else if (raiz>=0)
		{
			printf("La ecuacion cuadratica es %0.2fx^2+%0.2fx+%0.2f\n",a,b,c);
			x1=(-b+ sqrt(raiz))/(2*a); //raiz 1
			x2=(-b- sqrt(raiz))/(2*a); //raiz 2
			printf("Raiz 1: %0.2f  Raiz 2: %0.2f\n", x1, x2);
		}
		else
			{
				x_real=-b/2*a; //raiz real, es igual ambas raices
				x1_imag=sqrt(-raiz)/(2*a); //raiz imaginaria 1
				x2_imag=-sqrt(-raiz)/(2*a); //raiz imaginaria 2
				printf("r0= %f j %+f;r1= %f j %-f\n",x_real ,x1_imag ,x_real ,x2_imag);
			}
	
	return(0);
}
