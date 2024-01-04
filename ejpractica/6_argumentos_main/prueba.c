#include <stdio.h>
#include <string.h>

int main (void)
{	
	char *p=NULL ,num[20];
	int i=0;
	
	scanf("%s", num);
	
	while(*(num+i)!= '.')
	{
		i++;
	}
		
	p=num+(i+1);

	printf("entero: %s\n", p);
	
	
	return(0);
}
