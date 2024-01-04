#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
	int entero=32000;
	char ascii[20];
	
	itoa(entero, ascii, 10); //el 10 es la base decimal
	
	printf("%s\n", ascii);
	
	return(0);
}

