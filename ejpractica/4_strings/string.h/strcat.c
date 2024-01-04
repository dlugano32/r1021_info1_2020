#include <stdio.h>
#include <string.h>

int main (void)
{

	char origen[20], *origen1="Damian", *origen2=" ", *origen3="Lugano";
	
	strcpy(origen, origen1);
	
	strcat(origen, origen2);
	strcat(origen, origen3);
	
	printf("%s\n", origen);
	
	return(0);
	
}

