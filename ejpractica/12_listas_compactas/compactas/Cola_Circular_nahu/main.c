#include "header.h"

int main(void){
	
	fifo_circular *lista;
	
	int opcion,salir=no,retorno,cant_elementos;
	
	tipo_elemento aux;
	
	printf("NOTA: El ejercicio pedía cargar como máximo 150 mediciones. Para probar el programa es recomendable ingresar una cantidad menor.¿Cuál es el máximo de mediciones que va a ingresar?: ");

	scanf("%d",&cant_elementos);

	lista = crear_fifo_circular(cant_elementos);

	if(lista == NULL){

		printf("ERROR al crear la lista..\n");

		return 1;

	}	

	do{

		printf("¿Qué Querés Hacer?\n1-Cargar una Medición\n2-Sacar una Medición\n3-Mostrar TODAS las mediciones\n4-Salir\n");
		
		fflush(stdin);
		
		scanf("%d",&opcion);
		
		switch(opcion){
			
			case 1:
							
				printf("Ingrese elemento: ");
				
				fflush(stdin);
				
				scanf("%f",&aux);	
				
				retorno = cargar_elemento_fifo_circular(lista,aux);		
				
				if(retorno < 0){

					printf("Error al cargar la medición!..\n");

				}

				SEPARADOR
				break;
			
			case 2: 
				retorno = sacar_elemento_fifo_circular(lista, &aux);
				
				if(retorno==0){

					printf("Saqué %0.2f \n",aux);

				}else{

					printf("ERROR al sacar la medición!..\n");

				}
				
				SEPARADOR
				break;
			
			case 3:
				
				retorno = mostrar_elementos_fifo_circular(lista);

				if(retorno!=0){

					printf("ERROR al mostrar las mediciones..\n");

				}
				
				SEPARADOR
				break;
			
			case 4:
				salir=si;
				SEPARADOR
				break;
			}
	
		}while(salir==no);
	
	eliminar_fifo_circular(lista);
	
	return 0;
	
	}	
