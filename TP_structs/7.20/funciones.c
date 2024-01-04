#include "7.20_lib.h"

struct Complex Suma(struct Complex  n1,struct Complex n2)
{
       struct Complex res;

       res.real=n1.real+ n2.real ;
       res.imag=n1.imag+n2.imag;

       return res;
}

struct Complex Resta(struct Complex n1, struct Complex n2)
{
       struct Complex res;

       res.real=n1.real - n2.real ;
       res.imag=n1.imag - n2.imag;

       return res;
}

struct Complex Multiplicacion(struct Complex n1, struct Complex  n2)
{
       struct Complex res;

       res.real= ( n1.real * n2.real ) + (-1 * (n1.imag * n2.imag) ); // i^2=-1
       res.imag= ( n1.imag * n2.real ) + ( n1.real * n2.imag );

       return res;
}

struct Complex Conjugado(struct Complex n)
{
       struct Complex res;

       res.real=n.real;
       res.imag= (n.imag) *-1;

       return res;
}

struct Complex Division(struct Complex n1, struct Complex n2)
{
       struct Complex res, conj, num, den;

       conj=Conjugado(n2);
       num= Multiplicacion( n1, conj);
       den = Multiplicacion(n2, conj);
       
       res.real=  num.real/den.real;
       res.imag= num.imag/den.real;

       return res;
}
