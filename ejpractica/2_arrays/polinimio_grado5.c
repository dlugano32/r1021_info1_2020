#include <stdio.h>
#include <math.h>

double Polinomio (int *, int);

int main(void)
{
	int polinomio[6];
	
	printf("Ingrese un polinimio de esta manera: a0+ a1x + a2x^2 + a3x^3 + a4x^4 + a5x^5\n");
	
	for(int i=0; i<6; i++)
	{
		scanf("%d", &polinomio[i]);
	}
	
	for(int j=-10; j<=10; j++)
	{
		printf("f(%d)= %0.0f\n",j, Polinomio(polinomio,j));
	}
	
	
	return(0);
}

double Polinomio (int *polinomio, int variable)
{
	double resultado=0;
	
	for(int i=0; i<6; i++)
	{
		resultado=resultado+ pow(variable,(i))*polinomio[i];

	}
	
	return resultado;
}
