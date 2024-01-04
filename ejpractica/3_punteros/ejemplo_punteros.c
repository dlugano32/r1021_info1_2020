#include <stdio.h>
#include <math.h>

void Potencia(int *,int *);

int main(void)
{
	int x,y;
	printf("Ingrese un numero 'x' e 'y' y se devolvera x^y\n");
	scanf("%d %d", &x,&y);
	
	Potencia(&x,&y);
	
	printf("\nLa potencia es: %d\n",x);
	
	
	
	return(0);
}

void Potencia(int *x,int *y)
{
	printf("Posición de x: %p\nPosición de y: %p\n",x,y);
	printf("Posición del puntero de x: %p\nPosicion del puntero de y: %p\n",&x,&y);
	printf("Contenido de x: %d\nContenido de y: %d",(*x),(*y));
	
	*x= pow((*x),(*y));
}
