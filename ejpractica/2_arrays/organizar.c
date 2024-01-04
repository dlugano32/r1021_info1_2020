#include <stdio.h>
#include <string.h>

#define N 10

int main(void)
{
	int vec[N], par[N], pos[N], i;
	int cont_par=0, cont_pos=0;
	
	for(i=0; i<N; i++)
	{
		scanf("%d", &(vec[i]));
	}
	
	for(i=0; i<N; i++)
	{
		if((vec[i]%2)==0)
		{
			par[cont_par]=vec[i];
			cont_par++;
		}
		
		if(vec[i]>0)
		{
			pos[cont_pos]=vec[i];
			cont_pos++;
		}
	}
	
	if(cont_par!=0)
	{
		printf("Vector par\n");
		
		for(i=0; i<cont_par; i++)
		{
			printf("%d\n", par[i]);
		}
	}else
		{
			printf("No hay componentes pares.\n");
		}
	
	if(cont_pos!=0)
	{
		printf("Vector positivo\n");
		for(i=0; i<cont_pos; i++)
		{
			printf("%d\n", pos[i]);
		}
	}else
		{
			printf("No hay componentes positivas.\n");
		}
		
	return(0);
}
