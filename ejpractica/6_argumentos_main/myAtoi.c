#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int myAtoi (char *, int );

int main(int argc, char **argv)
{
	int i, acum=0;
	
	for(i=1; i<argc; i++)
	{
		acum=acum+(myAtoi(*(argv+i), (int)strlen(*(argv+i) ) ) );
		
	}
	
	printf("%d\n", acum);
	
	return 0;
}

int myAtoi (char *num, int n)
{
	int res=0, i=0, j=0;
	
	for (i=0, j=n; i<n ; i++, j--)
	{
		res=res+ ( (*(num+i)-'0')* pow(10,j-1));
	}
	
	return res;
}
