#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * my_itoa (int );

int main (void)
{
        int j=-123456789;
        char *num=NULL, *p=NULL;

        num=my_itoa(j);
        p=strcat(num, "aaa");
        printf("My_itoa--> %s\n", p);

        return 0;
}

char * my_itoa (int num)
{
        int i=0, j=0, length=0, flag=0;
        char *str=NULL, *str_r=NULL;
        
        str=(char *) malloc(sizeof(char));
        if(str==NULL)
        {
                printf("Error - En el malloc\n");
                exit(1);
        }

        if((num) < 0)
        {
                num= num * (-1);
                flag=1;
        }
        
        while( num > 0)
        {
                str[i]= num % 10 + '0';     //Tomo el digito menos significativo
                num= num/10;                //El digito que ya tome, lo borro dividiendolo x 10
                str=realloc(str, sizeof (char) * (i+2) );
                i++;
        }
        
        if(flag==1)
        {
                str[i]='-';
                str=realloc(str, sizeof (char) * (i+2) );
                i++;
        }

        str[i]='\0';

        /*Una vez que tengo el numero invertido, simplemente lo doy vuelta*/
        length=strlen(str);
        str_r=(char* )malloc(sizeof(char) * length);

       for(i=0, j= (length-1) ; i < length ; i++, j--)
       {
              *(str_r+i)=*(str+j); //copio en str_r el string invertido
       }
       str_r[length]= '\0'; //le seteo el null

       free(str);
        
        return str_r;
}