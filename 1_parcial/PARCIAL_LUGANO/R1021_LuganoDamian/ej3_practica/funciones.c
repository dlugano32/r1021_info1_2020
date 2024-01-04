#include "mylib.h"

char *copiaStr(char *str)
{
       int length=0;
       char *str_ret=NULL;

       length=(int) strlen(str);

       str_ret=(char*) malloc(sizeof(char) * (length +1)); // el +1 es para el NULL
       strcpy(str_ret, str);

       return str_ret;
}