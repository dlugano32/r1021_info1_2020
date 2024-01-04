/*
Compilacion: gcc -o main 7.1.c 7.1_lib.c -Wall

Ejecutar: ./main
*/
#include <stdio.h>

struct division
{
       int cociente;
       int resto;
};

struct division dividir (int , int);

