#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { false, true } bool;

bool emptyString (const char*);

int main(void)
{
	bool boolean;
	const char cadena[]={'D','a','m','i','\0'};//Cambiar aca el string que se le quiere pasar a la funcion

	//~ scanf("%s", cadena);
	
	boolean=emptyString(cadena);
	
	if(boolean==true)
	{
		printf("El string está vacio\n");
	} 
	else
		{
			printf("El string NO está vacio\n");
			printf("El contenido es: %s\n", cadena);
		}
	
	
	return(0);
}

bool emptyString(const char* cadena )
{
	if(*(cadena)=='\0')
	{
		return true;
	}
	else 
		{
			return false;
		}
}	

