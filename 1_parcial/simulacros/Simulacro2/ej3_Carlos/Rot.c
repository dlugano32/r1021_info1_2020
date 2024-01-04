#include "Rot.h"

int rot_13(char *str, char *str_mod)
{
       int i=0, r=0, cont=0;

       for(i=0; *(str +i)!='\0'; i++)
       {
              if( (*(str + i)>='a' && *(str + i)<='z') || (*(str + i)>='A' && *(str + i)<='Z') || *(str + i)==' ')
              {
                     if( (*(str+i)>='a' && *(str + i)<='m') || (*(str+i)>='A' && *(str + i)<='M') )
                     {
                            *(str_mod+i)=*(str+i) + 13;
                            cont++;
                     }
                     else if ( (*(str+i)>='n' && *(str + i)<='z') || (*(str+i)>='N' && *(str + i)<='Z') )
                     {
                            *(str_mod+i)=*(str+i) - 13;
                            cont++;
                     }
                     else
                     {
                        *(str_mod+i)= *(str + i); //para el espacio
                     }
              }
              else
              {
                     r=-1; //si no tiene ninguno de esos caracteres devuelve -1
              }
       }

       if(r!=-1)
       {
              r=cont; //si es correcto el string devuelvo la cantidad de caracteres modificados;
       }

       return r;
}