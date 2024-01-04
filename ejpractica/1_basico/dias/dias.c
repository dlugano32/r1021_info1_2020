#include <stdio.h>

int main (void)
{
	char a;
	scanf ("%c", &a);
	
	switch (a)
	{
		case 'l' :
		case 'L' :
					printf("Lunes\n");
							break;
		case 'm' :
		case 'M' :
					printf("Martes\n");
							break;
		case 'x' :
		case 'X' :
					printf("Miercoles\n");
							break;
						
		case 'j' :
		case 'J' :
					printf("Jueves\n");
							break;
				
		case 'v' :
		case 'V' :
					printf("Viernes\n");
							break;
							
		case 's' :
		case 'S' :
					printf("Sabado\n");
							break;
							
		case 'd' :
		case 'D' :
					printf("Domingo\n");
							break;
						
		default : printf("Error\n");
							
		
	}
}
