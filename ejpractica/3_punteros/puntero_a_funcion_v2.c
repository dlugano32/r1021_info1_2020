#include <stdio.h>
#include <string.h>

int suma(int, int, int ( * )(int));
int cuadrado (int);
int cubo (int);

int main (void)
{
       int a, b, choice;
       int ( *f[2] )( );

       f[0]=cuadrado;
       f[1]=cubo;

       printf("Que operacion desea hacer? [0] cuadrado  [1] cubo\n");
       scanf("%d", &choice);
       printf("Ingrese dos numeros\n");
       scanf("%d %d", &a, &b);
       
       printf("El resultado es: %d\n", suma(a, b, f[choice]));

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