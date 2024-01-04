#include <stdio.h>
#include <math.h>

#define j 100

int main (void)
{
	int a,num[j];
	int c1=0, c2=0,c3=0,c4=0, c5=0, c6=0, temp1=0, temp2=0, fin=0;
	char tecla;
	
	do
	{
	printf("\nIngrese 100 numeros para hacer operaciones\n");
	
	for(int i=0; i<j; i++)
	{
		printf("Numero n°%d: ",i);
		scanf("%d",&num[i]);
	}
	
	printf("Ingrese un numero del 1 al 4\n");
	scanf("%d",&a);
	
	switch(a)
	{
		case 1: for(int y=0; y<j; y++)
				{
					if(num[y]>50)
					{
						c1++;
					}
					
					if(num[y]<1000)
					{
						c2++;
					}
					
					temp1=sqrt(num[y]);
					temp2=pow(temp1,2);
					
					if(num[y]==temp2)
					{
						c3++;
					}
				}
				printf("Cantidad de numeros mayores a 50: %d\n",c1);
				printf("Cantidad de numeros menores menores a 1000: %d\n",c2);
				printf("Cantidad de numeros que tengan raiz entera: %d\n",c3);
				break;
				
		case 2: for (int x=0;x<j;x++)
				{
					if(num[x]<0 && num[x]%2==0)
					{
						c4++;
					}
					
				printf("Los numeros que son menores a 0 o pares: %d\n", c4);
					
				}
				break;
				
		case 3: for (int z=0; z<j; z++)
				{
					if(num[z]%8==0)
					{
						c5++;
					}
					
					if(num[z]%9==0)
					{
						c6++;
					}
				}
				
				printf("Los numeros que son multiplos de 8: %d\n", c5);
				printf("Los numeros que son multiplos de 9: %d\n", c6);
				
				break;
		
		case 4: fin=1;
				break;
		
		default : 	perror("Opcion invalida");
					printf("Ingrese la tecla y: ");
					setbuf(stdin,NULL);
					scanf("%c", &tecla);
					
					if (tecla=='y')
					{
						printf ("\x1B[2J;\x1B[1;1H");
					}
					else 
					{
						fin=1;
					}
			
	}
	}while(fin!=1);
	
}
