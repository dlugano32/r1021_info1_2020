#include <stdio.h>

#define n 6

int main (void)
{
	int array[n],pares[n], impares[n], iguales[n];
	int menu, n_pares=0, n_impares=0, n_iguales=0, aux=0, aux2=0;
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &array[i]);
	}
	
	printf("\nSi desea contabilizar los numeros pares y ordenarlos descendentemente\n");
    printf("presione 1\n");
    printf("Si desea contabilizar los numeros impares y ordenarlos descendentemente\n");
    printf("presione 2\n");
    printf("Si desea visualizar los numeros repetidos y ordenarlos descendentemente\n");
    printf("presione 3\n");
    
    scanf("%d", &menu);
    
    switch(menu)
    {
		case 1:		for(int i=0; i<n; i++)
					{
						if(array[i]%2==0)
						{
							pares[n_pares]=array[i];
							n_pares++;
							
						}
					}
					
					for(int j=0; j<n_pares; j++)
					{
						for (int k=j+1; k<n_pares; k++)
						{
							if(pares[j]<pares[k])
							{
								aux=pares[j];
								pares[j]=pares[k];
								pares[k]=aux;
								
							}
						}
					}
					
					for(int x=0; x<n_pares; x++)
					{
						printf("Vector par n°%d: %d\n",x+1 ,pares[x]);
					}
					
					break;	
					
					
		case 2:		for(int i=0; i<n; i++)
					{
						if(array[i]%2!=0)
						{
							impares[n_impares]=array[i];
							n_impares++;
							
						}
					}
					
					for(int j=0; j<n_impares; j++)
					{
						for (int k=j+1; k<n_impares; k++)
						{
							if(impares[j]<impares[k])
							{
								aux2=impares[j];
								impares[j]=impares[k];
								impares[k]=aux2;
								
							}
						}
					}
					
					for(int x=0; x<n_impares; x++)
					{
						printf("Vector impar n°%d: %d\n",x+1 ,impares[x]);
					}
					
					break;
					
		
		case 3:		for(int i=0; i<n; i++)
					{
						for (int j=i+1; j<n; j++)
						{
							if(array[i]==array[j])
							{
								iguales[n_iguales]=array[i];
								n_iguales++;
							}
						}
					}
					
					for(int k=0; k<n_iguales; k++)
					{
						printf("Valores que se repiten: %d\n", iguales[k]);
					}
					
					break;
			
		default: printf("Opcion incorrecta");
	}
      
	return (0);
}
