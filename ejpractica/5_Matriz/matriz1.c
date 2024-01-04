#include <stdio.h>

int main(void)
{
	int matriz [4][5]=	{	{6,6,6,6,6},
							{5,5,5,5,5},
							{4,4,4,4,4},
							{2,2,2,2,2},
						};

	for(int i=0; i<4; i++)
		{
			printf("Fila %d\n",(i+1));
			
			for(int j=0; j<5; j++)
			{	
				
				printf("Columna %d: %d\t", (j+1), matriz[i][j]);
			}
			
			printf("\n");
		}
	
	return(0);
}

