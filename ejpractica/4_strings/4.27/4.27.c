#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

typedef enum {false, true} bool;

bool valIP( char*);
bool valMail( char*);
bool valCC( char*);
int split(int, int);

int main(void)
{
	char cadena[100];
	int opcion;
	size_t length;
	
	printf("Ingrese palabra a validar (IP/Mail/Tarjeta de credito):\n");
	fgets(cadena, 100, stdin);
	
	printf("Qué desea validar:\n[1] IP\n[2] Mail\n[3] Tarjeta de crédito\n");
	scanf("%d", &opcion);
	
	length=strlen(cadena);
	cadena[length-1]='\0'; //le saco el 0xa (enter)
	
	switch(opcion)
	{
		case 1:	
				if(valIP(cadena)==true)
				{
					printf("IP verificada\n");
				}
				else
					{
						printf("IP no verificada\n");
					}
					
				break;
			
		case 2: 
				if(valMail(cadena)==true)
				{
					printf("Mail verificado\n");
				}
				else
					{
						printf("Mail no verificado\n");
					}
					
				break;

		case 3: 
				if(valCC(cadena)==true)
				{
					printf("CC verificada\n");
				}
				else
					{
						printf("CC no verificada\n");
					}
					
				break;
				
		default: printf("Opcion incorrecta\n");	
	}
		
	return 0;
}

bool valIP(char *cadena) //xxx.xxx.xxx.xxx
{
	char *s=NULL, *p=NULL, s_aux[100];
	int valor=0, i=0;

	strcpy(s_aux,cadena);

	if(strlen(cadena)!=15) //verifico el largo del IP
	{
		return false;
	}
	else
	{
		for( i=0; i<16 ; i=i+4) //me voy saltando de a 4 para ir verificando los 3 digitos
		{
			s=(s_aux+i); //apunto a las primer direccion de cada numero despues del "."
						
			p=strtok(s,"."); //token hasta el punto, es decir deberia tener 3 numeros
				
			if(strlen(p)!=3) //compruebo que sean 3 digitos
			{
				return false;
			}
			else
				{
					valor=atoi(p); //paso ascii a int
					
					if(valor>255 || valor<0) //verifico que el numero sea valido
					{
						return false;
					}
				}
		}
	}
	
	return true;
}

bool valMail( char *cadena)
{
	char *dir=NULL,*dom=NULL, s_aux[100];
	int i=0, j=0, cont_=0;
	size_t length_dir;
	
	strcpy(s_aux,cadena);
	
	dir=strtok(s_aux,"@"); //divido el string auxiiar en la dir y el dom
	
	length_dir=strlen(dir);
	
	dom=(s_aux+length_dir+1);
	
	if(length_dir>24)
	{
		printf("Aca no deberia entrar\n");
		return false;
	}
	else
	{
		for(i=0; i<length_dir; i++)
		{
			if(isalnum(*(dir+i))==0) //cuando encuentra un caracter especial devuelve un 0
			{
				if((*(dir+i))!='.' && (*(dir+i))!='_' && (*(dir+i))!='-' )
				{
					return false;
				}
			}
		}
		
		for(j=0; *(dom+j)!='\0'; j++)
		{
			if((*(dom+j))=='.') //verifico que tengo minimo un punto en el dominio
			{
				cont_++;
			}
		}
		
		if(cont_==0)
		{
			return false;
		}
	}
	
	return true;
}

bool valCC( char *cadena)
{
	char *s=NULL, *p=NULL, s_aux[100];
	int i=0, j=0, aux=0, acum=0;
	
	strcpy(s_aux,cadena);
	
	if(strlen (cadena)!=19) //xxxx xxxx xxxx xxxx //16 numeros + 3 espacios
	{
		return false;
	}
	else
		{
			for( i=0; i<20 ; i=i+5) //hago lo mismo que hice con la IP pero con la tarjeta de credito y el espacio
			{
				s=(s_aux+i);
				
				p=strtok(s," ");
				
				if(strlen(p)!=4) //verifico que entre espacios tenga 4 digitos
				{
					return false;
				}
				

				for(j=3, aux=0; j>=0; j--) //algoritmo de luhn
				{
					if( j==2 || j==0)
					{
						aux=split(j, atoi(p));
						aux=aux*2;
						
						if(aux>=10)
						{
							aux=(aux-10)+(aux/10);
						}
						
						acum=acum+aux;
						
									
					}
					else
						{
							aux=split(j, atoi(p));
							acum=acum+aux;
						}
				}
			}
			
			printf("%d",acum);

			if(((acum*9)%10)!=0)
			{
				return false;
			}
		}
		
		
	
	return true;
}

int split (int n, int num) 	//funcion para divir cifras de numeros, se le pasa como argumento el numero 
{						   //y el numero de cifra que se quiere, siendo el numero más grande el mas siginificativo (4 cifras (3,2,1,0))
	int res;
	
    while(n>0)
    {
        num=num/10;
        n--;
	}
	
	res=num%10;
	
    return res;
}
