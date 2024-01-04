#include <stdio.h>

int main () 
{
       FILE *fp;
       char str[]={"Death Row Records"};

       fp = fopen("file.txt", "w+");
       fputs(str, fp);

       fclose(fp);
       return(0);
}