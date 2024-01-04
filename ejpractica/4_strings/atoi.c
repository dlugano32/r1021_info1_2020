#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
	int entero;
	char ascii[20];
	
	strcpy(ascii, "23.1");
	entero=atoi(ascii); // atof --> ascii to int
	
	entero++;
	
	printf("%d\n", entero);
	
	return(0);
}
