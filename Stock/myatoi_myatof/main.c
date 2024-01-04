#include "myatoi.h"

int main(int argc, char**argv)
{
       int num1=0;
       float num2=0;

       num1= myAtoi( *(argv+1), strlen(*(argv+1) ) );
       num2=myAtof( *(argv+2), strlen(*(argv+2) ) );

       printf("Entero= %d\n",  num1);
       printf("Float= %f\n",  num2);

       printf("resultado %f\n", (float) num1+num2);

       return 0;
}