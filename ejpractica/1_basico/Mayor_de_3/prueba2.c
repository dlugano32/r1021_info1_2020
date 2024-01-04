#include <stdio.h>

int main (void)
{
	int a, b, c;

	/* Entradas */
	printf("Ingrese a: ");
	scanf("%d", &a);
	printf("Ingrese b: ");
	scanf("%d", &b);
	printf("Ingrese c: ");
	scanf("%d", &c);
	
	if(a>b) {
        if(a>c) {
            printf("El mayor es a = %d\n", a);
        } else {
            printf("El mayor es c = %d\n", c);
        }
    } else {
          if(b>c) {
              printf("El mayor es b = %d\n", b);
          } else {
              printf("El mayor es c = %d\n", c);
          }
      }
      return 0;
}
