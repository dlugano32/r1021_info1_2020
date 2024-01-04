#include <stdio.h>
#include <string.h>

int main (void)
{
	char s[20];
	size_t length;
	
	fgets(s, 20, stdin);
	
	length=strlen(s);
	
	printf("%ld\n", (length-1)); //le resto uno porque el fgets toma el enter
	
	printf("%d\n", (int)(strlen(s)-1));
	
	return(0);
}
