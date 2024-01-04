#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int valor=1,fin=0;
	float carrito=1;
	int c1=0,c2=0,c=0, m=0, p=0;
	int alfa=0;
	while(fin!=1)
	{
	 printf("Ingrese el valor del carrito:\n");
	 scanf("%f",&carrito);
	 
	 if (carrito<0)
	 {
		 printf("Ingrese un valor positivo.\n");
		 c++;
	 } 
	 
	 if (c==3)
	 {   
		 perror("Error");
		 fin=1;
	 } else if(carrito>0)
		{
			fin=1;
		}
	}
	m=carrito;
	if(carrito>0)
	 {
		for(int i=0; valor>0;i++)
		{
			printf("\nParticipante n°%d ingrese un valor: ", i+1);
			scanf("%d", &valor);
		
			alfa= abs(valor-carrito);
		
			if((carrito*0.15)<alfa)
			{
				c1++;
			}
			
			if((carrito*0.01)> alfa)
			{
				c2++;
			}
			
			if(m>(alfa))
			{
				m=(valor-carrito);
				p=i+1;
			}
			
			alfa=0;
		}
	 }
	
	printf("Cantidad de participantes que arriesgaron valores mayores al 15 del valor del carrito: %d\n", c1);
	printf("Cantidad de participantes que participantes arriesgaron valores menores al 1 del valor del carrito: %d\n", c2);
	printf("El participante que estuvo mas cerca del valor fue el participante n°%d\n", p);
}
