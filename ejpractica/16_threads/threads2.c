#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

/*Variables globales*/
//Son necesarias para manejar threads
 pthread_t id[2];	// Vector con los descriptores de cada thread
 int ret1=0, ret2=0;    //Valore de retorno de cada thread
 
 void *sumar (void *arg) /*thread 1*/
{
        int v1=4, v2=5;
        /* Salir del thread/función en el que estamos */
        //void pthread_exit(void *retval);
        ret1=v1+v2;
        pthread_exit(&ret1);
}

void *restar (void *arg) /*thread 2*/
{
        int v1=4, v2=5;
        /* Salir del thread/función en el que estamos */
        //void pthread_exit(void *retval);
        ret2=v1-v2;
        pthread_exit(&ret2);
}

int main (void)
{
        int i=0, error=0;
        int *p[2]; //Apunta a los valores de retorno de los threads
        void* ( *function[2] )(void*) ={sumar, restar}; // Puntero a funcion los cuales le asgino a cada thread

        for(i=0; i<2; i++)
        {
                /* Creando un thread */
                //int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
                error=pthread_create(&id[i], NULL, function[i], NULL);

                if(error == 0)
                {
                        printf("---Thread creado exitosamente---\n");
                }
                else
                {
                        perror("Con la funcion pthread_create\t");
                        return -1;
                }
        }

        for(i=0; i<2; i++)
        {
                /* Volviendo a unirse*/
                //int pthread_join(pthread_t thread, void **retval);
                pthread_join(id[i], (void **)&p[i]);
                printf("Valor de retorno del thread %d =\t %d\n", i+1, *p[i]);
        }
        
        return 0;
}