#include <stdio.h>

int main(void)
{
	int a,a1,b,b1;
	float sup1=0, sup2=0, porcentaje=0;
	int fin=0, fin1=0, fin2=0;
	
	do 
	{
		do
		{
			printf("\nIngrese medidas del frente y fondo del terreno :\n");
			scanf("%d %d", &a, &a1);
			
			if (a<0 || a1<0)
			{
			
				printf("Por favor ingrese numeros mayores a 0");
			}
			else
			{
				fin1=1;
			}
				
		}while (fin1!=1);
	
	do
		{
			printf("\nIngrese medidas del frente y fondo del deposito :\n");
			scanf("%d %d", &b, &b1);
			
			if (b<0 || b1<0)
			{
				printf("Por favor ingrese numeros mayores a 0");
			}
			else
			{

				fin2=1;
			}
				
		}while (fin2!=1);
		
	sup1=a*a1;
	sup2=b*b1;
	porcentaje=(sup2/sup1)*100;
	printf("Superficie del terreno :%0.2fm\n", sup1);
	printf("Superficie del deposito :%0.2fm\n", sup2);
	printf("Porcentaje del terreno construido: %0.2f%\n", porcentaje);
	
	
	if (a==0 && a1==0 && b==0 && b1==0)
	{
		fin=1;
	}
	
	} 
	while(fin!=1);
	
	
}
