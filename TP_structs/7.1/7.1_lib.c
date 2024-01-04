#include "7.1_lib.h"

struct division dividir (int dividendo, int divisor)
{
       struct division resultado;

       resultado.cociente=(int)dividendo/divisor;
       resultado.resto= dividendo%divisor;

       return resultado;
}