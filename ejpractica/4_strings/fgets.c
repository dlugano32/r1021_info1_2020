#include <stdio.h>
#include <string.h>

#define N 20

int main (void)
{
	char pS[N];
	
	fgets(pS, N, stdin);
	
	printf("%s", pS);
	
	return (0);
}
