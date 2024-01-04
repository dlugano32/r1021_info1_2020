#include "header.h"

int main(void)
{

        int fd_archivo, retorno, flag_lista_llena = no;
        char buffer[32];
        fifo_circular *lista;
        struct Nodo aux;
        time_t timer_lista_llena;

        lista = crear_fifo_circular(3);

        if (lista == NULL)
        {

                printf("ERROR al crear la lista\n");

                return -1;
        }

        fd_archivo = open("in.txt", O_RDONLY);

        if (fd_archivo < 0)
        {

                perror("ERROR al abrir el archivo: ");

                return (-1);
        }

        while (1)
        {

                retorno = read(fd_archivo, buffer, 5 * sizeof(char));

                if (retorno < 0)
                {

                        perror("ERROR al leer el archivo: ");

                        return -2;
                }

                *(buffer + 5) = '\0';

                aux.temp = atof(buffer);

                printf("%0.2f ", aux.temp);

                retorno = read(fd_archivo, buffer, 8 * sizeof(char));

                if (retorno < 0)
                {

                        perror("ERROR al leer el archivo: ");

                        return -2;
                }

                *(buffer + 8) = '\0';

                strcpy(aux.hora, buffer);

                printf("%s ", aux.hora);

                retorno = read(fd_archivo, buffer, 9 * sizeof(char));

                if (retorno < 0)
                {

                        perror("ERROR al leer el archivo: ");

                        return -2;
                }

                *(buffer + 8) = '\0';

                strcpy(aux.fecha, buffer);

                printf("%s\n", aux.fecha);

                retorno = cargar_elemento_fifo_circular(lista, aux);

                if (retorno == COLA_LLENA) //si la cola está llena
                {
                        printf("Cola llena (Se sobreescribió el primer elemento) \n");

                        if (flag_lista_llena == no) //Si la cola se acaba de llenar, guardo la hora en la que se llenó y levanto el flag
                        {
                                timer_lista_llena = time(NULL);
                                flag_lista_llena = si;
                        }

                        if (time(NULL) - timer_lista_llena >= MAX_SEGS)
                        {
                                printf("ERROR. Lista llena por mas de %d segs. \nSaliendo..\n",MAX_SEGS);
                                eliminar_fifo_circular(lista);

                                exit(-1);
                        }
                        sleep(2);
                }
                else //si la cola no está llena, bajo el flag.
                {
                        flag_lista_llena = no;
                }
        }

        eliminar_fifo_circular(lista);

        return 0;
}