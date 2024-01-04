#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int myAtoi (char *, int );

int main(int argc, char **argv)
{
	int F1=0, F2=0, i=0, j=0, val=0;
	char *operador=NULL, *p=NULL;
	
       for(i=1; i<argc; i++)
       {
              p=*(argv+i);
              if(i==1 || i==3)
              {
                     for(j=0; *(p+j); j++)
                     {
                            if( (*(p+j)>='0' && *(p+j)<='9') || *(p+j)=='-' ) { } //valido que lo ingresado sea correcto
                            else
                            {
                                   val=1;
                            }
                     }
              }
       }

       if(val!=1)
       {
              F1=(myAtoi(*(argv+1), (int)strlen(*(argv+1) ) ) ); //primer numero ingresado
              F2=(myAtoi(*(argv+3), (int)strlen(*(argv+3) ) ) );//segundo numero ingresado
              
              printf("%d\n", F1);
              printf("%d\n", F2);
              
              operador=*(argv+2);
              
              switch(*operador)
              {
                     case '+':	printf("El resultado: %d\n", F1+F2);
                                          break;
                     
                     case '-':	printf("El resultado: %d\n", F1-F2);
                                          break;	
                     
                     case'/':	printf("El resultado: %0.2f\n", (float)F1/F2);
                                          break;
                     
                     case 'x':	printf("El resultado: %d\n", F1*F2);
                                          break;
                            
                     default:	printf("El operador no es valido\n");
              }
       }
       else
       {
              printf("Los valores ingresados son incorrectos\n");
       }
	
	return 0;
}

int myAtoi (char *num, int n) //n es cantidad de caracteres
{
	int res=0, i=0, j=0, flag_neg=0; 
	
       if(*num=='-') //pregunto si el primer caracter es el signo menos
              {
                     flag_neg=1;
                     
                     for(i=1; i<=n ; i++) //le saco el signo menos para operar
                     {
                            *(num+(i-1)) = *(num+(i));	
                     }
                     
                     n--;//como le saco el signo menos tiene length-1
              }

	for (i=0, j=n; i<n ; i++, j--)
	{
		res=res+ ( (*(num+i)-'0')* pow(10,j-1));
	}

       if(flag_neg==1)
	{
		res= res*(-1);
       }
	
	return res;
}
