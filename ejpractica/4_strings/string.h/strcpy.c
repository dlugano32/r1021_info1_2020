#include <stdio.h>
#include <string.h>


int main (void)
{
	char origen[]="Roto", destino[]="Rotopercutora";
	
	//~ fgets(origen, 20, stdin);
	
	strcpy(destino, origen);
	
	printf("%s\t%s\n", destino, origen);

	return(0);
}


