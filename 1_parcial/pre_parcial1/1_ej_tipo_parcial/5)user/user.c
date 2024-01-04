/*5) Realizar un programa que permita extraer el nombre de usuario que lo ejecutó a un nuevo string, que se forme de la siguiente manera: 
“El usuario <nombre> ejecuto este programa”, donde el campo <nombre> es el nombre de usuario extraido de la variable de entorno. 
Finalmente, imprimir este nuevo string en pantalla.*/

/*
void main(int argc,char *argv[],char *envp[]) {
	int i=0;

	while(envp[i]!=NULL) {
		if(strstr(envp[i],"USER=")) {
			printf("%s\n", envp[i]);
		}
		i++;
	}
}*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
       int i=0;
       
       while(envp[i] !=NULL)
       {
              if(strstr(envp[i],"USER=")!= NULL)
              {
                     printf("El usuario %s ejecuto este programa\n", envp[i]);
              }
              i++;
       }
}