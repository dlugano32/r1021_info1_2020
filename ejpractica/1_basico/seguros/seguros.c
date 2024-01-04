#include <stdio.h>

#define h 2
#define a 2020 //año actual
int main(void)
{
	int anio_poliza[h], anio_d[h], km[h], cant_siniestros[h];
	int c1=0, c2=0, m=0, promedio=0;
	
	for( int i=0;i<h;i++)
	{
		printf("\nDominio n°%d\n", i+1);
		printf("Ingrese año de la primer póliza para el dominio.\n");
		scanf("%d", &anio_poliza[i]);
		printf("Ingrese año del dominio\n");
		scanf("%d", &anio_d[i]);
		printf("Ingrese cantidad de kilometros\n");
		scanf("%d", &km[i]);
		printf("Ingrese cantidad de siniestros\n");
		scanf("%d", &cant_siniestros[i]);
		
		if((a-anio_d[i])>10 || km[i]>100000)
		{
			c1++;
		}
		
		if((a-anio_poliza[i])>5 && cant_siniestros[i]<3)
		{
			c2++;
		}
		
		if(km[i]>m)
		{
			m=km[i];
		}
		
		promedio=promedio+(km[i]/(a-anio_d[i]));
	}
	
	printf("Cantidad de dominios que posean más de 10 años de antigüedad o más de 100.000 kmts: %d\n", c1);
	printf("Cantidad de dominios que posean una póliza con más de 5 años de fidelidad a la compañía y menos de 3 siniestros: %d\n", c2);
	printf("Mayor kilometraje que posee un dominio: %d\n", m);
	printf("Promedio de kilómetros por año del total de dominios: %d \n", (promedio/h));
}
