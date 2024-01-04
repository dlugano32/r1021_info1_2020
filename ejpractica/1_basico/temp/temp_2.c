#include <stdio.h>

float conversion(float valor, char e_origen, char e_destino);

int main(void)
{
	float valor;
	char e_origen, e_destino;
	printf("ingrese una temperatura mayor a al cero absoluto\n");
	scanf("%f", &valor);
	printf("Ingrese la escala del valor ingresado\n");
	scanf (" %c", &e_origen);
	printf("Ingrese la escala a la que lo quiere convertir\n");
	scanf (" %c", &e_destino);
		
	printf("El valor final es %0.1f %c\n", conversion(valor,e_origen,e_destino), e_destino);
	
	return (0);
}

float conversion(float valor, char e_origen, char e_destino)
{
	
	switch(e_origen)
	{
		case 'c': 
		case 'C':	switch(e_destino)
					{
						case 'f':	
						case 'F':	valor=(9.0/5 * valor + 32);
									break;
						
						case 'k':
						case 'K':	valor=(valor +273.15);
									break;
						
						default : printf("Escala incorrecta\n");
					}
					break;
					
		case 'f':
		case 'F':	switch(e_destino)
					{
						case 'c':
						case 'C':	valor=((valor - 32)* 5.0/9);
									break;
						
						case 'k':
						case 'K':	valor=(((valor - 32)* 5.0/9)+273.15);
									break;
						
						default : printf("Escala incorrecta\n");
					}
					break;
					
		case 'k':
		case 'K':	switch(e_destino)
					{
						case 'c':
						case 'C':	valor= valor-273.15;
									break;
									
						case 'f':
						case 'F':	valor=((valor-273.15)*(9.0/5)+ 32);
									break;
									
						default : printf("Escala incorrecta\n");
									
					}
					break;
					
		default : printf("Escala incorrecta\n");

	}
	
	return valor;
}
