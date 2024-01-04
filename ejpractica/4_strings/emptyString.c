#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//~ int emptyString (char*);

int main(void)
{
	//~ int boolean;
	char cadena[10];
	//~ size_t length;

	
	scanf("%s", cadena);
	printf("%s\n", cadena);
	//~ length=strlen(cadena);
	
	//~ printf("%ld",length);
	
	if(cadena[0]=='\0')
	{
		printf("Está vacio\n");
	}
	else
		{
			printf("%s\n", cadena);
		}
	
	/* boolean=emptyString(cadena);
	
	if(boolean==1)
	{
		printf("El string está vacio\n");
	} 
	else
		{
			printf("El string NO está vacio\n");
		}*/
	
	
	return(0);
}

/*int emptyString(char* cadena )
{
	if(*(cadena)=='\0')
	{
		return 1;
	}
	else 
		{
			return 0;
		}
}	*/
