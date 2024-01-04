/**
	\file oper.c
	\brief Contiene funciones que realizan operaciones matematicas
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2010.06.05
	\version 1.0.0
	\todo Agregar mas operaciones.
*/
//--------------
//-- Includes --
//--------------
#include "oper.h"

/**
	\fn int operSuma (int a, int b)
	\brief Suma dos numeros enteros y retorna el resultado	
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2010.06.05
	\param a Primer operando a sumar
	\param b Segundo operando a sumar
	\return Retorna la suma de los operandos pasados como parametros
	\todo Modificar para que verificar overflow.	
*/
int operSuma (int a, int b)
{
	
	return (a + b);
}

/**
	\fn int operMult (int a, int b)
	\brief Multiplica dos numeros enteros y retorna el resultado	
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2010.06.22
	\param a Primer operando a sumar
	\param b Segundo operando a sumar
	\return Retorna la suma de los operandos pasados como parametros
*/
int operMult (int a, int b)
{
	
	return (a * b);
}
