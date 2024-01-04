#include <stdio.h>
#include <string.h>

int suma(int, int, int ( * )(int));
int resta(int, int, int ( * )(int));
int cuadrado (int);
int cubo (int);

int main (void)
{
       int a, b, choice1, choice2;
       int ( *f[2] )( ), ( *ff[2] )( );

       f[0]=cuadrado;
       f[1]=cubo;

       ff[0]=suma;
       ff[1]=resta;
       
       printf("Que operacion desea hacer? [0] suma  [1] resta\n");
       scanf("%d", &choice1);
       printf("De [0] cuadrado  [1] cubo?\n");
       scanf("%d", &choice2);
       printf("Ingrese dos numeros\n");
       scanf("%d %d", &a, &b);
       
       printf("El resultado es: %d\n", (*ff[choice1]) (a, b, f[choice2]));

       return 0;
}

int cuadrado (int x)
{
       return x*x;
}

int cubo (int x)
{
       return x*x*x;
}

int suma(int a, int b, int ( *f )(int ))
{
       return (*f)(a) + (*f)(b);
}

int resta(int a, int b, int ( *f )(int ))
{
       return (*f)(a) - (*f)(b);
}