#include "mylib.h"

int validar_CC(char * cc)
{
       int a=0, b=0, S=0;
       int i=0, j=0, r=0, aux=0, flag=0;
       char *p=NULL;

       if(strlen(cc)==19) // xxxx xxxx xxxx xxxx 19 caracteres en total
       {
              for(i=0; *(cc+i)!='\0' ; i++)
              {
                     if( (*(cc+i)>='0' && *(cc+i)<='9') || *(cc+i)==' ') //me fijo si tiene solo numeros o espacios
                     {
                            if( *(cc+i)==' ' )
                            {
                                   j++;
                            }
                     }
                     else
                     {
                            flag=1;
                     }      
              }

              if(j==3 && ( *(cc+4)== ' ' && *(cc+9)==' ' && *(cc+14)==' ' ) ) //si tengo 3 espacios en los lugares correctos, recien ahi empiezo a analizar el numero
              {
                     p=cc; //uso al puntero p como auxiliar

                     for(i=0, j=0; *(cc+i)!='\0' ; i++)
                     {
                            if(*(cc+i)==' ')
                            {
                                   p=cc+ (i+1);
                                   j=0;
                            }
                            else
                            {
                                   if( (j+1)%2==0 ) //para los numeros de la tarjeta que se encuentren en la posicion par (sin tener en cuenta el 0)
                                   {
                                          b=b+ (*(p+j) - '0') * 1;
                                   }
                                   else 
                                   {
                                          if( (*(p+j) -'0' )*2 >= 10 )
                                          {
                                                 aux= (*(p+j) -'0' ) * 2;
                                                 a= a + (aux/10 + aux%10);
                                          }
                                          else
                                          {
                                                 a=a + (*(p+j) -'0' ) * 2;
                                          }
                                   }
                                   j++;
                            }
                     }
              }
              else
              {
                     flag=1; //si esta mal la sintaxis flag == 1
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