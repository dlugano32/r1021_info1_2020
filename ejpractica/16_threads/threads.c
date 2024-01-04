#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

/*Variables globales*/
//Son necesarias para manejar threads
 pthread_t id[2];	// Vector con los descriptores de cada thread
 int ret1=0, ret2=0;    //Valore de retorno de cada thread

void *function (void *arg)
{
        /* Retornar el pthread ID actual */
        //pthread_t pthread_self(void);
        pthread_t tid = pthread_self();
        
        /* ¿Son tid1 y tid2 el mismo thread?                  */
        /* pthread_t no tiene forma portable de ser comparado */
        //int pthread_equal(pthread_t tid1, pthread_t tid2);
        if( pthread_equal(id[0], tid) )
        {
                printf("-Soy el thread numero 1-\n");
                ret1=1;
                /* Salir del thread/función en el que estamos */
                //void pthread_exit(void *retval);
                pthread_exit( &ret1);
        }
        else
        {
                printf("-Soy el thread numero 2-\n");
                ret2=2;
                /* Salir del thread/función en el que estamos */
                //void pthread_exit(void *retval);
                pthread_exit( &ret2);
        }
}


int main (void)
{
        int i=0, error=0;
        int *p[2]; //Apunta a los valores de retorno de los threads

        for(i=0; i<2; i++)
        {
                /* Creando un thread */
                //int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
                error=pthread_create(&id[i], NULL, &function, NULL);

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