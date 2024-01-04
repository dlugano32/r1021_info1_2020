#include <stdio.h>

#define N 20

int main(void)
{
       FILE *fp;
       char *p, str[N];
       
       fp=fopen("archivo.txt","r");
       p=fgets(str, N, fp);
       printf("%s", p);

       fclose(fp);
       return(0);
}