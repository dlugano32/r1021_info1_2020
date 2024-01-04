#include <stdio.h>
#include <string.h>

int main (void)
{	

	char origen[]= {"Rotopercutoramiento"};
	const char substr[]="to";
	char *s;
	
	//~ fgets(substr, 20, stdin);
	
	s = strstr( origen, substr);
	
	printf("El substring es: %s\n", s);

        s = strstr( s+1, substr);
	
	printf("El substring es: %s\n", s);
	
	
	return(0);
}
