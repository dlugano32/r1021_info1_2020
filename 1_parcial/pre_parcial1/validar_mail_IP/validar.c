#include "validar.h"

int validar_correo(char *mail)
{
       int i=0, j=0, pos=0, r=0;

       for(i=0, j=0; *(mail +i)!='\0'; i++)
       {
              if( (*(mail+i)>='a' && *(mail+i)<='z') || (*(mail+i)>='0' && *(mail+i)<='9') || *(mail+i)=='.' || *(mail+i)=='_' ||*(mail+i)=='-' || *(mail+i)=='@')
              {
                     if(*(mail+i)=='@')
                     {
                            j++;
                            pos=i; //guardo la posicion de donde esta el arroba
                            if(j>1)
                            {
                                   r=1;
                            }
                     }
              }
              else
              {
                     r=1;
              }
       }

       for(i=1, j=0; *(mail + pos + i)!='\0'; i++) //me fijo si despues del arroba tengo almenos un punto
       {
              if( *(mail + pos + i) =='.')
              {
                     j++;
              }
       }
       if(j==0)
       {
              r=1;
       }
    
       return r;
}

int validar_IP(char* IP)
{
       int i=0, j=0, k=0, r=0;
       
       for(i=0; *(IP+i); i++)
       {
              if(*(IP+i)>='0' && *(IP+i)<='9')
              {
                     j++;
              }
              else if(*(IP+i)=='.')
              {
                     k++;
              }
              else
              {
                     r=1;
              }
       }

       if( (j==12 && k==3) && (*(IP+3)=='.' && *(IP+7)=='.' && *(IP+11)=='.' ) ) //me fijo que esten los puntos en los lugares correctos y que tenga una cantidad correcta de numeros y puntos
       {
              for(i=0; i<15; i=i+4)
              {
                     if( myAtoi( IP+i , 3) > 255)
                     {
                            r=1;
                     }
              }
       }
        else
       {
              r=1;
       }

       return r;
}

int validar_CC(char * cc)
{
       int a=0, b=0, S=0;
       int i=0, r=0, aux=0, flag=0;

       if(strlen(cc)==16) // xxxx.xxxx.xxxx.xxxx 16 numeros en total
       {
              for(i=0; *(cc+i)!='\0' ; i++)
              {
                     if(*(cc+i)>='0' && *(cc+i)<='9')
                     {
                            if( (i+1)%2==0 ) //para los numeros de la tarjeta que se encuentren en la posicion par (sin tener en cuenta el 0)
                            {
                                   b=b+ (*(cc+i) - '0') * 1;
                            }
                            else 
                            {
                                   if( (*(cc+i) -'0' )*2 >= 10 )
                                   {
                                          aux= (*(cc+i) -'0' ) * 2;
                                          a= a + (aux/10 + aux%10);
                                   }
                                   else
                                   {
                                          a=a + (*(cc+i) -'0' ) * 2;
                                   }
                            }
                     }
                     else
                     {
                            flag=1;
                     }
              }
              S=a+b;

              if(S%10 == 0 && flag==0)
              {
                     r=0;
              }
              else
              {
                     r=-2;
              }
       }
       else
       {
              r=-1;
       }

       return r;
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