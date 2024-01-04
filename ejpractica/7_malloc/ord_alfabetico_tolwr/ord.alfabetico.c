#include "ABC.h"

int main(void)
{
	int i=0, j=0;
	char c, word[TAM], *p=NULL, ** adr=NULL;
	size_t length;
	
	adr=(char **) malloc(sizeof(char *));
	if(adr==NULL)
	{
		printf("ERROR\n");
	}
	
	do
	{
		fgets(word, TAM, stdin);
		length=strlen(word);
		*(word+(length-1))='\0'; //borro el 0xa
		length--;
		
		p=(char *)malloc(sizeof(char)*length);
		if(p==NULL)
		{
			printf("ERROR\n");
		}
		strcpy(p,word);
		*(adr+i)=p;
		
              c= (*(*(adr+i)));

              if(c!='/')
              {
                     adr=(char **) realloc(adr,(i+2)* sizeof(char*));
                     if(adr==NULL)
                     {
                            printf("ERROR\n");
                     }
              }
              else
                     {
                            free(p);
                            *(adr+i)=NULL;
                     }

		i++;
	}
	while(c!='/');

	ordenABC(adr,i);
	imprimir_nombres(adr);
	
	for(j=0; *(adr+j)!=NULL; j++)
	{
		free(*(adr+j));
	}
	
	free(*(adr+j));//libero el null
	
	free(adr);
	
	return 0;
}
