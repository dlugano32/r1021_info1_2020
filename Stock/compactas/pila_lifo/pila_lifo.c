#include "pila.h"

int main (void)
{
        int fin=0, choice=0, num=0, num2=0;
        struct pila *pila;

        pila=(struct pila *) malloc (sizeof(struct pila));         //solo para que tenga sentido la funciona eliminar

        pila_init(pila);
        
        while (fin != 1)
        {
                printf("\nMenu:\n1)Escribir\n2)Leer\n3)Listar\n4)salir\n");
                scanf("%d", &choice);

                switch (choice)
                {
                        case 1:     
                                        printf("Push numero\t");
                                        scanf("%d", &num);
                                        if (push(pila, num) )
                                        {
                                                printf("Pila llena\n");
                                        }
                                        break;

                        case 2:
                                        if ( pop(pila, &num2) )
                                        {
                                                printf("Pila vacia\n");
                                        }
                                        else
                                        {
                                                printf("Pop numero\t%d\n",num2);
                                        }
                                        break;

                        case 3:
                                        if( listar(pila) == 1)
                                        {
                                                printf("Pila vacia!");
                                        }
                                        break;
                        case 4:
                                        eliminar_pila(pila);
                                        fin=1;
                                        break;

                        default:        printf("Argumento invalido\n");
                }       
        }

        return 0;
}