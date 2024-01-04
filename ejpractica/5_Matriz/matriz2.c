#include <stdio.h>

#define f 3
#define c 3
int main(void)
{
	int matriz [f][c];
	int i,j;

	for(i=0; i<f; i++)
		{
			printf("Fila %d\n",(i+1));
			
			for(j=0; j<c; j++)
			{	
				scanf("%d", &(matriz[i][j]));
			}
			
			printf("\n");
		}
		
		for(i=0; i<f; i++)
		{
			printf("\n");
			
			for(j=0; j<c; j++)
			{	
				
				printf("%d\t", matriz[i][j]);
			}
			
			printf("\n");
		}
	
	return(0);
}
