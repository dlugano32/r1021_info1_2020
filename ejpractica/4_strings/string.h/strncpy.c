#include <stdio.h>
#include <string.h>

#define length 13

int main (void)
{

	char origen[]="Damian Lugano", destino[20];
	
	strncpy(destino, origen, length);
	
	destino[13]='\0';
	
	printf("%s\n", destino);
	
	return(0);
	
}
