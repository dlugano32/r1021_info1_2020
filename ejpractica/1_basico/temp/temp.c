#include <stdio.h>

float conversion(float valor, char e_origen, char e_destino);

int main(void)
{
	float valor, resultado;
	char e_origen, e_destino;
	printf("ingrese una temperatura mayor a al cero absoluto\n");
	scanf("%f", &valor);
	printf("Ingrese la escala del valor ingresado\n");
	scanf (" %c", &e_origen);
	printf("Ingrese la escala a la que lo quiere convertir\n");
	scanf (" %c", &e_destino);
	
	resultado=conversion(valor,e_origen,e_destino);
	
	printf("El valor final es %0.1f %c\n", resultado, e_destino);
	
	return (0);
}

float conversion(float valor, char e_origen, char e_destino)
{
	float resultado;

	switch(e_origen)
	{
		case 'c': 
		case 'C': 	resultado = (9.0/5 * valor + 32);
					break;
					
		case 'f':
		case 'F':	resultado= ((valor - 32)* 5.0/9);
					break;
					
		default : printf("Escala incorrecta\n");

	}
	
	return resultado;
}
