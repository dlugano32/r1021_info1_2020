#include "mylib.h"

void my_toupper (char *mail)
{      
       int i=0;

       for(i=0; *(mail +i)!= '\0'; i++)
       {
              if(isalpha(*(mail+i))!=0)   // si uso isalnum solo me va a detectar los caracteres especiales y NO los numeros, por lo que tengo que usar isalpha
              {
              *(mail +i)= *(mail + i) - ' ';
              }
       }
}

int validar_correo (char *mail) //tenia la logica del true false al reves, si era true era correcto. Lo corregi
{
       char *dir=NULL,*dom=NULL, *p=NULL;
	int i=0, j=0, flag=0, length=0;

       length= (int) strlen(mail);
       p= (char *) malloc( sizeof(char) * (length+1));
       strcpy(p, mail); //hago esto para no trabajar directamente sobre el dato y despues poder reutilizarlo

       for(i=0; *(mail + i)!='\0'; i++) //me fijo si tiene mas de un @ ya que una vez que hace el strok me borra todos los @ al mismo tiempo (por mas que tenga uno)
       {
              if(*(mail +i )== '@')
              {
                     flag++;
                     if(flag>1)
                     {
                            return true;
                     }
              }
       }      

	dir=strtok(p,"@"); //divido el string auxiiar en la dir y el dom
       dom=strtok(NULL, "@");

       length= (int) strlen(dir);

       for(i=0; i<length; i++)
	{
              
		if(isalnum(*(dir+i))==0) //cuando encuentra un caracter especial devuelve un 0
		{
			if((*(dir+i))!='.' && (*(dir+i))!='_' && (*(dir+i))!='-' )  //tiene que ser diferente a todo esto al mismo tiempo por eso &&
			{
				return true;
			}
		}
       }
		
	for(j=0; *(dom+j)!='\0'; j++)
	{
              if(isalpha(*(dom+j)) == 0)
              {
                     if((*(dom+j))=='.') //verifico que tengo minimo un punto en el dominio
                     {
                            flag++;
                     }
                     else
                            {
                                    return true;
                            }
              }
	}
		
	if(flag==0)
	{
		return true;
	}

       free(p);
	
	return false;
}


int imprimirNombre (char * mail) // me olvide de poner la variable
{

      int i=0;

      if(mail ==NULL)
      {
             return true;
      }
       else
              {
                     printf("El nombre del mail es: ");
                     for(i=0; *(mail+i)!='@'; i++)
                     {
                            printf("%c", *(mail + i) );
                     }
                     printf("\n");
              }
       
       return false;
}

int imprimirDominio (char * mail) //me olvide de poner la variable cuando copio el protitipo
{
      int i=0, flag=0;

       if(mail ==NULL)
      {
             return true;
      }
       else
              {
                      printf("El nombre del dominio es: ");
                     for(i=0, flag=0; *(mail+i)!='\0'; i++)
                     {
                            if(flag==1)
                            {
                                   printf("%c", *(mail +i));
                            }

                            if(*(mail+i)=='@')
                            {
                                   flag++;
                            }
                     }
                     printf("\n");
              }
       
       return false;
}
