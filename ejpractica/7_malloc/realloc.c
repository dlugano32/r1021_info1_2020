#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

int main(void)
{
	char word[N], c, *p=NULL, **vec=NULL;
	int i=0, j=0;
	size_t length;
	
	vec=(char **) malloc(sizeof(char *));
	
	do
	{
		fgets(word, N , stdin);
		length=strlen(word);
		*(word+(length-1))='\0'; //borro el 0xa
		length--;
		
		p=(char*) malloc(length * sizeof(char));
		strcpy(p,word);
		*(vec+i)=p;
		
		vec=(char **)realloc(vec,(i+2)*sizeof(char *));
		
		c= (*(*(vec+i)));
		
		i++;
	}
	while(c!='/');
	
	*(vec+i)=NULL;
	
	for(j=0; *(vec+j)!=NULL; j++)
	{
		printf("%s\n", *(vec+j));
	}

	for(j=0; *(vec+j)!=NULL; j++)
	{
		free(*(vec+j)); //libero todos los strings que fui reservando para guardar en p
	}
		
	free(*(vec+j)); //Libero el NULL
	
	free(vec); //Libero el vector donde guardaba 
	
	return 0;
}

