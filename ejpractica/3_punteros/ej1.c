#include <stdio.h>
#include <stdlib.h>

void largoVariable(long int *);

int main(void)
{
	long int a;
	scanf("%ld", &a);
	
	largoVariable(&a);
	
	return(0);
}

void largoVariable(long int *a)
{	
	unsigned char *p;
	p=(unsigned char*)a;
	

	for( int i=0; i<8; i++)
	{
		printf("%#x\n",*(p+i));
	}
}
