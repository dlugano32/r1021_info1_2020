/**
	\file main.c
	\brief Programa ejemplo que llama a una funcion alojada en otro archivo .c
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2010.06.05
	\version 1.0.0
*/
//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include "main.h"
#include "oper.h"

/**
	\fn int main (void)
	\brief Pide el ingreso de dos numeros enteros y realiza su suma utilizando 
	la funcion operSuma, si los dos operandos son cero sale del programa.
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2010.06.05
	\return Retorna siempre cero.
	\bug No verifica el rango de los números ingresados.
*/
int main(void)
{
int a, b;
int resultadoS;
int resultadoM;

	do {
		//-- Ingreso de datos --
		printf ("Ingrese numero:\r\n");
		scanf ("%d", &a);
		printf ("Ingrese numero:\r\n");
		scanf ("%d", &b);
		
		//-- llamo a la funcion ---
		resultadoS = operSuma (a, b);
		resultadoM = operMult (a, b);
		//-- Imprimo el resultado de la operacion --
		printf ("\r\n%d + %d = %d\r\n", a,b, resultadoS);
		printf ("\r\n%d * %d = %d\r\n", a,b, resultadoM); 
		
	} while ((a != 0) || (b != 0));
	
	
	return (0);
}
