#include <stdio.h>
#include <string.h>

int main (void)
{	

	const char origen[50]= "Rotopercutora";
	char *s;
	
	char n;
	
	scanf("%c", &n);
	
	s=strchr(origen, n);
	
	printf("El substring es: %s\n", s);
	
	
	return(0);
}

