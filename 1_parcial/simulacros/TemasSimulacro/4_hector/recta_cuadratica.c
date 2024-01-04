/*Realizar un programa que por medio de un menú permita cargar todos los coeficientes juntos:
a) recta y=mx+b
b) ecuación cuadrática y= ax2 +bx+c
c) Salir
E imprima en pantalla los valores obtenidos en el rango elegido.
Cada función solicitara el ingreso de los valores:
a) en el caso de la recta pendiente y ordenada al origen
b) en el caso de la ecuación cuadrática los valores de a b y c
Para ambos casos el rango de valores también debe ser pedido para ser ingresado por el usuario igual que
la cantidad de puntos a evaluar en el entorno ingresado.*/

#include "mylib.h"

int main (void)
{
       int fin=1, a=0, b=0, c=0, rango1=0, rango2=0, x=0;
       char menu;

       do
       {
              printf("\nMENU:\n");
              printf("a) recta y=mx+b\nb) ecuación cuadrática y= ax2 +bx+c\nc) Salir\n");
              setbuf(stdin, NULL);
              scanf("%c", &menu);
              
              switch(menu)
              {
                     case 'a': 
                                   printf("Ingrese la pendiente y la ordenada al origen\t a.x+b\n");
                                   scanf("%d %d", &a, &b);
                                   printf("Entre que puntos desea evaluar la funcion?\n");
                                   scanf("%d %d", &rango1, &rango2);

                                   for(x=rango1; x<rango2; x++)
                                   {
                                          printf("f(%d): %d\t", x, recta(a,b,x) );
                                   }
                                   break;

                     case 'b': 
                                   printf("Ingrese los valores a b c\t y= ax2 +bx+c\n");
                                   scanf("%d %d %d", &a, &b, &c);
                                   printf("Entre que puntos desea evaluar la funcion?\n");
                                   scanf("%d %d", &rango1, &rango2);

                                   for(x=rango1; x<rango2; x++)
                                   {
                                          printf("f(%d): %d\t", x, cuadratica (a,b,c,x) );
                                   }

                                   break;

                     case 'c': fin=0;
                                   break;
                     
                     default: printf("Opcion incorrecta\n");
              }
       }
       while(fin!=0);

       return 0;
}