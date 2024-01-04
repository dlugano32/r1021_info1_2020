#include <stdio.h>
#include <string.h>

float suma(int, int);
float resta(int, int);
float producto(int, int);
float division(int, int);

int main(void)
{
       int a, b, choice;
       float (*f [4])()={suma, resta, producto, division};
       
       printf("Que operacion desea hacer? [0] suma  [1] resta  [2] producto  [3] division\n");
       scanf("%d", &choice);
       printf("Ingrese dos numeros\n");
       scanf("%d %d", &a, &b);

       printf("Su resultado es: %0.2f\n", (*f [choice]) (a,b));

       return 0;
}

float suma (int num1, int num2)
{
	return (float)num1+num2;
}

float resta(int num1, int num2)
{
	return (float)num1-num2;	
}
float producto(int num1, int num2)
{
	return (float)num1*num2;
}

float division (int num1, int num2)
{
	return (float)num1/num2;
}