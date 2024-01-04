#include "header.h"

fifo_circular *crear_fifo_circular (int tam_lista){

	fifo_circular *lista;
	
	lista = (fifo_circular*) malloc (sizeof(fifo_circular)); //esto solamente para que tenga un poco mas de sentido la funcion eliminar lista, libera los dos punteros dejando la memoria libre para usar
	
	if(lista==NULL){
		
		printf("ERROR al pedir memoria para lista..\n");
		
		return NULL;

		}
	
	lista->BUFFER = (tipo_elemento*) malloc(sizeof(tipo_elemento) * tam_lista);	
	
	if(lista->BUFFER == NULL){
		
		printf("ERROR al pedir memoria para el vector de la lista..\n");
		
		return NULL;

		}
	
	lista->escribir = 0;
	
	lista->leer = 0;

	lista->tam_buffer = tam_lista;

	return lista;
	
	}

int cargar_elemento_fifo_circular (fifo_circular *lista, tipo_elemento elemento){
	
        int retorno = 0;

	if(lista->flag_lleno == si){

		 //Lo que la hace circular es que al ver que la lista está llena, no cancela la operación si no que la reescribe
		lista->leer++;	//Hace falta incrementar de dónde voy a leer, por que acabo de pisar el primer elemento.
		lista->leer %= lista->tam_buffer;
                retorno = COLA_LLENA;

	}
	
	lista->BUFFER [lista->escribir] = elemento;

	lista->escribir++;

	lista->escribir %= lista->tam_buffer; //Si llego a la ultima posición, lo devuelve a 0
	
	lista->flag_vacio = no; //Como acabo de guardar un elemento, la lista NO está vacia

	if(lista->escribir == lista->leer){
 
		lista->flag_lleno = si;

	}

	return retorno;

}

void eliminar_fifo_circular (fifo_circular *lista){
	
	free(lista->BUFFER);
	
	free(lista);
	
	}
