#include "black_list.h"

void imprimir(char **vec)
{
	int i=0;
	
	for(i=0; *(vec+i)!=NULL; i++)
	{
		printf("%s ",*(vec+i));
	}

       printf("\n");
}

