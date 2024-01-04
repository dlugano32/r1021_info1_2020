#include "myatoi.h"

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

float myAtof (char *num, int n)
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

