#include <stdio.h>
#include <string.h>

void substring(char *, char *, int , int );

int main (void)
{
	char st_salida[30], st_entrada[30];
	int pos, n;
	
	fgets(st_entrada,30,stdin);
	
	scanf("%d", &pos);
	scanf("%d", &n);
	
	substring(st_salida, st_entrada, pos, n);
	
	printf("El substring: %s\n",st_salida);

	return(0);
}

void substring(char *st_salida, char *st_entrada, int pos, int n)
{
	int i;
	char *p;
	
	p=st_entrada+(pos-1);
	
	for(i=0; i<n; i++)
	{
		*(st_salida+i)= *(p+i);
	}
	
	st_salida[i+1]='\0';
}
