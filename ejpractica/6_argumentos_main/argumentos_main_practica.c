#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i,j;
	char *p=NULL;
	
	for(i=1;i<argc; i++)
	{
		printf("%s\n",*(argv+i));
		p=(*(argv+i));
		
		for(j=0; *(p+j)!='\0'; j++)
		{
			printf("%c\t", *(p+j));
		}
		printf("\n");
	}
	return 0;
}

