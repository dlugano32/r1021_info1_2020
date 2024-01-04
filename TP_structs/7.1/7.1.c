#include "7.1_lib.h"

int main (void)
{
       int dividendo, divisor;
       struct division operacion;

       printf("Ingrese dividendo y luego el divisor\n");
       scanf("%d %d", &dividendo, &divisor);

       operacion=dividir(dividendo, divisor);

       printf("Cociente= %d\nResto= %d\n", operacion.cociente, operacion.resto);

       return 0;
}

