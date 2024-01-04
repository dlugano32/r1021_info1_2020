#include <stdio.h>

int main(void)
{
	long int num=0, mul=1;

	for(int i=0;i<10;i++)
	{
		num=num+3*mul;
		printf("%ld\n",num);
		mul=mul*10;
	}
	
}
