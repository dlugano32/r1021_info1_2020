#include "cola.h"

int main (void)
{
        int fin=0, choice=0, num=0, num2=0;
        struct cola *c;

        c=(struct cola *) malloc (sizeof(struct cola));         //solo para que tenga sentido la funciona eliminar

        cola_init(c);
        
        while (fin != 1)
        {
                //system("clear");
                printf("\nMenu:\n1)Escribir\n2)Leer\n3)listar\n4)salir\n");
                scanf("%d", &choice);

                switch (choice)
                {
                        case 1:     
                                        printf("Push numero\t");
                                        scanf("%d", &num);
                                        fflush(stdin);

                                        if( push(c, num) ==1 )
                                        {
                                                printf("Cola llena\n");
                                        }

                                        break;

                        case 2:
                                        if ( pop(c, &num2) )
                                        {
                                                printf("Cola vacia!\n");
                                        }
                                        else
                                        {
                                                printf("Pop numero\t%d\n",num2);
                                        }
                                        break;

                        case 3:         
                                        if (listar(c)==1)
                                        {
                                                printf("Cola vacia!\n");
                                        }
                                        break;
                        case 4:
                                        eliminar_cola(c);
                                        fin=1;
                                        break;

                        default:        printf("Argumento invalido\n");
                }       
        }

        return 0;
}