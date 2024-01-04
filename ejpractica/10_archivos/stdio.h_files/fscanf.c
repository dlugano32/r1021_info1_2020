#include <stdio.h>

#define N 20

int main(void)
{
       FILE *fp;
       int num;
       char str[N];
       
       fp=fopen("archivo2.txt","r");
       fscanf(fp, "%s %d", str, &num);
       printf("%s\n", str);
       printf("%d\n", num);

       fclose(fp);
       return(0);
}