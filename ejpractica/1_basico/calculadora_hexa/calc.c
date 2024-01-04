#include <stdio.h>

int suma (int num1, int num2);
int resta(int num1, int num2);
int producto(int num1, int num2);
int division (int num1, int num2);
int eleccion (char operacion, int num1, int num2);

int main(void)
{
	char base, operacion;
	int num1, num2, resultado;
	
	printf("Ingrese la base en la que desea realizar el calculo [d/o/h]\n");
	scanf("%c", &base);
	
	switch(base)
	{
		case 'd': 
		case 'D': 	printf("Ingrese los dos numeros con los que desea hacer operaciones\n");
					scanf("%d \n %d", &num1, &num2);
					
					printf("Que operacion desea hacer?\n");
					scanf(" %c", &operacion);
					
					resultado=eleccion(operacion, num1, num2);
					
					printf("\nEl resultado es: %d\n", resultado);
					
					break;
			
		case 'o':
		case 'O':	printf("Ingrese los dos numeros con los que desea hacer operaciones\n");
					scanf("%o \n %o", &num1, &num2);
					
					printf("Que operacion desea hacer?\n");
					scanf(" %c", &operacion);
					
					resultado=eleccion(operacion, num1, num2);
					
					printf("\nEl resultado es: %o\n", resultado);
					
					break;
					
		case 'h':
		case 'H':	printf("Ingrese los dos numeros con los que desea hacer operaciones\n");
					scanf("%x \n %x", &num1, &num2);
					
					printf("Que operacion desea hacer?\n");
					scanf(" %c", &operacion);
					
					resultado=eleccion(operacion, num1, num2);
					
					printf("\nEl resultado es: %x\n", resultado);
					
					break;
					
		default: printf("Operacion invalida\n");					
	}
	
	return (0);
}

/*Funciones*/

int eleccion (char operacion, int num1, int num2)
{
	int resultado;
	switch(operacion)
	{
		case '+': 	resultado=suma(num1,num2);
					break;
									
		case '-':	resultado=resta(num1,num2);
					break;
									
		case '*':	resultado=producto(num1,num2);
					break;
									
		case '/':	resultado=division(num1,num2);
					break;
						
		default:	printf("Operacion invalida\n");
							
	}
	
	return resultado;
}

int suma (int num1, int num2)
{
	int resultado = num1+num2;
	return resultado;
}

int resta(int num1, int num2)
{
	int resultado = num1-num2;
	return resultado;	
}
int producto(int num1, int num2)
{
	int resultado = num1*num2;
	return resultado;
}

int division (int num1, int num2)
{
	int resultado = num1/num2;
	return resultado;
}


