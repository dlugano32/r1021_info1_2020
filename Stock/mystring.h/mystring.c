#include "mystring.h"

int my_strlen (char *str)
{
       int i=0;

       while(*(str+i)!='\0')
       {
              i++;
       }

       return i;
}

void my_strcpy (char *destino , char *origen) //OJO con la memoria
{
       int i=0;

       for(i=0; *(origen +i)!='\0'; i++)
       {
              *(destino +i)= *(origen+i);
       }

       *(destino+i)='\0';
}

void my_strncpy (char *destino , char *origen, int n)
{
       int i=0;

       for(i=0; *(origen +i)!='\0' && i!=n; i++)
       {
              *(destino +i)= *(origen+i);
       }

       *(destino+i)='\0';
}

void my_strcat (char *destino, char *origen)
{      
       int length=0, i=0;

       while(*(destino+i)!='\0')
       {
              i++;
       }
       length=i;

       for(i=0; *(origen+i)!='\0'; i++)
       {
              *(destino+ (length+i) )= *(origen+i); //piso el NULL en la primera pasada
       }
}

int my_strcmp (char *str1, char *str2)
{
       int fin=1, dif=0, i=0;

       while ( (*(str1 +i) == *(str2 + i) ) && fin==1)
       {
              if(*(str1 +i) == '\0' && *(str2 + i)=='\0')
              {
                     dif=0;
                     fin=0;
              }
              i++;
       }

       if(fin ==1)
       {
              dif= *(str1+i) - *(str2+i);
       }

       return dif;
}

int my_strncmp (char *str1, char *str2, int n)
{
       int fin=1, dif=0, i=0;

       while ( (*(str1 +i) == *(str2 + i) ) && fin==1)
       {
              if((*(str1 +i) == '\0' && *(str2 + i)=='\0') || i==(n-1))
              {
                     dif=0;
                     fin=0;
              }
              i++;
       }

       if(fin ==1)
       {
              dif= *(str1+i) - *(str2+i);
       }

       return dif; 
}

void strlwr (char *str)
{
       int i=0;

       for(i=0; *(str + i)!='\0'; i++)
       {
              if(*(str + i)>='A' && *(str + i)<='Z')
              {
                     *(str + i)= *(str + i)+ ' ';
              }
       }
}

void strupr(char *str)
{
       int i=0;

       for(i=0; *(str + i)!='\0'; i++)
       {
              if(*(str + i)>='a' && *(str + i)<='z')
              {
                     *(str + i)= *(str + i) - ' ';
              }
       }
}

void replace (char *str, char new, char old)
{
       int i=0;

       for(i=0; *(str + i)!='\0'; i++)
       {
              if(*(str+i)==old)
              {
                     *(str+i)=new;
              }
       }
}

void left_trim (char *str)
{
       int i=0, j=0, esp=0;

       while(*(str+i)==' ') //cuento cuantos espacios tengo
       {
              i++;
       }
       esp=i;

       for(i=0; i<esp; i++)
       {
              for(j=0; *(str+j)!='\0'; j++)
              {
                     *(str+j)=*(str+ (j+1));
              }
       }
}

void right_trim (char *str)
{
       int i=0, esp=0, length=0;

       while(*(str+i)!='\0')
       {
              i++;
       }
       length=i;
       i=0;//pongo el contador en 0

       while(*(str+ (length-1-i) )==' ') //cuento cuantos espacios tengo
       {
              i++;
       }
       esp=i;

       *(str+ (length-esp))='\0'; // el -1 es por el NULL

}

int my_strstr (char *big, char *sub)
{
       int i=0, j=0, length=0, ret=0;

       while(*(big+i)!='\0')
       {
              i++;
       }
       length=i;

       if(*(big + (length -1) ) == 10) //pregunto si es enter la ultima posicion del string antes del null
       {
              length --;
              *(big+ length ) = '\0'; //si tiene enter le pongo null arriba
       }

       i=0;//vuelvo a poner el contador en 0

       while(*(sub+i)!='\0')
       {
              i++;
       }
       length=i;

       if(*(sub + (length -1) ) == 10) //pregunto si es enter la ultima posicion del string antes del null
       {
              length --;
              *(sub+ length ) = '\0'; //si tiene enter le pongo null arriba
       }

       for(i=0, j=0; *(big +i)!='\0'; i++)
       {
              if(*(big+i) == *(sub+j))//si hay tantas coincidencias seguidas con el largo del substring entonces es valido
              {
                     j++;
              }
              else
              {
                     j=0;
              }

              if(j==length) //pregunto si la cantidad de coincidencias que hubo con el string es igual al largo
              {
                     ret=1;
              }
       }

       return ret;
}


void string_reverse (char *str, char *str_r)
{
       int i=0, j=0, length=0;

       while(*(str+i)!='\0')
       {
              i++;
       }
       length=i;

       if(*(str + (length -1) ) == 10) //pregunto si es enter la ultima posicion del string antes del null
       {
              length --;
              *(str + length ) = '\0'; //si tiene enter le pongo null arriba
       }

       for(i=0; *(str+i)!='\0'; i++)
       {
              if( *(str+i)>= 'A' && *(str+i)<='Z') //paso todo a minusculas
              {
                     *(str+i)=*(str+i)+' ';
              }
       }
	
       for(i=0, j= (length-1) ; i < length ; i++, j--)
       {
              *(str_r+i)=*(str+j); //copio en str_r el string invertido
       }
       
       str_r[length]= '\0'; //le seteo el null

}