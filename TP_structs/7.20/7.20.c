#include "7.20_lib.h"

int main(void)
{
       struct Complex n[2], res;
       struct Complex (*operaciones[4])()={Suma, Resta ,Multiplicacion, Division};
       int i=0, choice=0;

       printf("Ingrese que operacion con numeros complejos quiere hacer:\n[1]Suma\n[2]Resta\n[3]Multiplicacion\n[4]Division\n[5]Conjugado\n"); 
       scanf("%d", &choice);

       if(choice > 0 && choice < 5) /* EL CASO 5 ES ESPECIAL PORQUE SOLO SE NECESITA UN NUMERO*/
       {
              printf("\nIngrese dos numeros complejos para operar.\n");
              for(i=0; i<2; i++)
              {
                     printf("Numero %d\n", i+1);
                     printf("Real:\t");
                     scanf("%f", &n[i].real);
                     printf("Imaginario:\t");
                     scanf("%f", &n[i].imag);
                     printf("\n");
              }

              res=(*operaciones[choice - 1])(n[0], n[1]); //Llamo a la funcion 
              printf("Resultado:\t%0.2f %0.2fi\n", res.real, res.imag);
       }
       else if(choice ==5)
       {
              printf("\nIngrese numero al que se le va a hacer el conjugado\n");
              printf("Real:\t");
              scanf("%f", &n[0].real);
              printf("Imaginario:\t");
              scanf("%f", &n[0].imag);

              res=Conjugado(n[0]);
              printf("\nResultado:\t%0.2f %0.2fi\n", res.real, res.imag);
       }
       else
       {
              printf("ERROR - Opcion ingresada incorrecta\n");
       }
       
       return 0;
}

