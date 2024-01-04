#include <stdio.h>
#include <string.h>

int main (void)
{
	int a=0;
	char string1[20], string2[20];
	int length;

	fgets(string1,20,stdin);
	fgets(string2,20,stdin);

	scanf("%d", &length);

	a=strncmp(string1,string2,length);
	
	printf("%d\n",a);
	
	return(0);
}

