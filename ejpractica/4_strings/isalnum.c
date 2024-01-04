#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (void)
{
	char origen;
	
	scanf("%c", &origen);

	printf("%d\n",isalnum(origen));
	
	return(0);
}
