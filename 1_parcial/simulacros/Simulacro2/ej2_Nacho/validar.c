#include "validar.h"

int validar (char *p)
{
       int i=0, r=0, flag=0;

       for(i=0; *(p+i)!='\0' ; i++)
       {
              if( (*(p+i)>= '0' && *(p+i)<='9') || *(p+i)==';' || *(p+i)=='.') //lo valido solo si es un numero, un punto y coma o un punto
              { }
              else
              {
                     r=-1;
              }

              if(*(p+i)==';')
              {
                     flag++;
                     if(*(p+ (i-1) )=='\0' || *(p+ (i+1) )=='\0'  ) //si el caracter anterior o posterior al punto y coma no es un numero, no lo valido. Para que no ponga (;3)
                     {
                            r=-1;
                     }
              }
       }

       if(flag!=1) //este flag es para saber si tiene al menos un punto y coma
       {
              r=-1;
       }

       return r;
}

float myAtof (char *num, int n) //esta funcion la tenia hecha de antes
{
	int i=0, j=0, k=0, flag_neg=0, flag_dec=0;
	float res=0;
	char *p=NULL;

	if(*num=='-') //pregunto si el primer caracter es el signo menos
	{
		flag_neg=1;
		
		for(i=1; i<=n ; i++) //le saco el signo menos para operar
		{
			*(num+(i-1)) = *(num+(i));	
		}
		
		n--;//como le saco el signo menos tiene length-1
	}
	
	for(i=0; i<n; i++) //me fijo sie tiene un punto
	{
		if(*(num+i)=='.')
		{
			flag_dec=1;
		}
	}
	
	if(flag_dec==1)
	{
		while(*(num+k)!= '.')
		{
			k++; // k va a ser el numero de cifras enteras que tengo
		}
				
		p=num+(k+1); //le asigno a p la posicion donde empiezan los decimales
		
		for (i=0, j=1 ; i < (n-k-1); i++, j++) //paso los decimales a float // n-k-1 es la cantidad de decimales--- n=largo total --- k=cantidad de enteros--- el -1 es porque tengo que tener en cuenta el punto '.'
		{
			res=res+ ( (*(p+i)-'0')* pow(10,(-j)));
		}
		
		n=k; //le asigno el largo de numero entero que tengo 
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

void liberar_memoria(float **matriz , int fila, int columna )
{
       int i=0;

       for(i=0; i<fila; i++)
       {
              free( *(matriz +i) );
       }

       free(matriz);
}

float producto_escalar(float **matriz)
{
       return (matriz[0][0] * matriz[1][0] + matriz[0][1] * matriz[1][1]);
}
