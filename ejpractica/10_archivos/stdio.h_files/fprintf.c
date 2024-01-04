#include <stdio.h>

//#define N 20

int main(void)
{
       FILE *fp;
       int num=33;
       char str[]={"Max Verstappen"};
       
       fp=fopen("archivo2.txt","a+");
       fprintf(fp, "%s %d", str, num);

       fclose(fp);
       return(0);
}