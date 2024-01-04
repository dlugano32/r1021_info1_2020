#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
	char *string="damian.gabriel.lugano@gmail.com", dest[20];
	const char limite[]=".";
	char *s;

	//~ s=&(string[6]);

	s=strtok(s,limite);
	
	printf("Domain: %s\n",s);
	
	return(0);
}
