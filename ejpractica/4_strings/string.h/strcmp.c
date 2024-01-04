#include <stdio.h>
#include <string.h>

int main (void)
{
	int a=0;
	char string1[20], string2[20];
	
	fgets(string1,20,stdin);
	fgets(string2,20,stdin);
	
	a=strcmp(string1,string2);
	
	printf("%d\n",a);
	
	return(0);
}
