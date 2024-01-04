#include <stdio.h>

int main (void)
{
	unsigned char a;
	
	printf("Ingrese un caracter y se lo clasificara.\n");
	scanf("%c", &a);

	if(47<a && a<58)
	{
		printf("Es un numero\n");
	} 
	else if (64<a && a<91)
		{
			printf("Es una letra mayuscula\n");
		}
		else if (96<a && a<123)
				{
					printf("Es una letra minuscula\n");
				}
				else
					{
						printf("Es otro caracter\n");
					}
		
	printf("En ascii es: %d\n", a); //imprimo el char como decimal para ver el ascii
	
	return (0);

}
