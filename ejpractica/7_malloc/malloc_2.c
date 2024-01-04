#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50
#define CANT 10

int main(void)
{
	char word[N], *p=NULL, **vec=NULL;
	int i=0;
	size_t length;
	
	vec=(char **) malloc(CANT*sizeof(char *)); //reservo una direccion donde guardar 10 direcciones
	
	for(i=0; i<CANT; i++)
	{
		fgets(word, N ,stdin);
		length=strlen(word);
		*(word+(length-1))='\0'; //borro el 0xa
		length--;
		
		p=(char *)malloc(length*sizeof(char));
		strcpy(p,word);
		*(vec+i)=p;
	}
	
	for(i=0; i<CANT; i++)
	{
		printf("%s\n", *(vec+i));
	}
	
	for(i=0; i<CANT; i++)
	{
		free(*(vec+i));
	}
	
	free(vec);
	
	
	return 0;
}
