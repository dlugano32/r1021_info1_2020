#include <stdio.h>
#include <math.h>

int main (void)
{
	int x,y;
	float r=0;
	int fin=0;
	
	do
	{
		printf("Ingrese dos puntos en un eje cartesiano\nCon el punto (0,0) se termina el programa\n");
		scanf("%d", &x);
		scanf("%d", &y);
		
		if (x>0 && y>0)
		{
			printf("Pertenece al primer cuadrante\n");
		}
		
		if(x<0 && y>0)
		{
			printf("Pertenece al segundo cuadrante\n");

		}
		
		if(x<0 && y<0)
		{
			printf("Pertenece al tercer cuadrante\n");
		}
		
		if(x>0 && y<0)
		{
			printf("Pertenece al cuarto cuadrante\n");

		}
		
		if(x==0 && y!=0)
		{
			printf("Pertenece pertenecen al eje de abscisas\n");
		}
		
		if( y==0 && x!=0 )
		{
			printf("Pertenece al eje de ordenadas\n");
		}
		
		if(x==0 && y==0) //si el punto es (0,0) me salgo del while y termina el programa
		{
			printf ("El punto se encuentra en el origen\n");
			fin=1;
		}	
		
		r=sqrt(pow(x,2)+pow(y,2));
		printf("La distancia al origen es: %0.3f\n\n", r);
		
	}while(fin!=1);
	
	return(0);
}


