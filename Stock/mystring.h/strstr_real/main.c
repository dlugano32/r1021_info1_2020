#include "mylib.h"

int main (void)
{	
	char origen[50]= "Rotopercutoramiento";
	char substr[]="to";
	char *s;
	
	//~ fgets(substr, 20, stdin);
	
	s = my_strstr( origen, substr);

       if(s!=NULL)
       {
	       printf("El substring es: %s\n", s);
       }
       else
       {
              printf("No hay coincidencias\n");
       }
	
	
	return(0);
}