#include "my.h"

int main(void)
{
        //Variables para la conexion
        int s = 0;                             // file descriptor del socket
        int n_sock = 0;                        //file descriptor del canal de datos usada por aceppt
        int port = 50000;                      //Puerto usado
        struct sockaddr_in cliente;            //struct para colocar datos en aceppt()
        socklen_t l_cliente = sizeof(cliente); //variable para guardar el tamaño de la estructura cliente usada en aceppt()
        char *buffer = NULL;

        FILE *fp = NULL, *fp1 = NULL;
        int i = 0, j = 0, cant = 0;
        float prom[24];
        struct medicion **vec = NULL;

        vec = (struct medicion **)malloc(sizeof(struct medicion *) * CANT); //Se la cantidad de estructuras porque se la cantidad de datos que voy a recibir
        if (vec == NULL)
        {
                perror("Error - Al asignar memoria");
                exit(-1);
        }

        fp1 = fopen("fluctuaciones.txt", "w"); //Abro el archivo donde voy a guardar las anomalias
        if (fp1 == NULL)
        {
                perror("Error - Al abrir el archivo\t");
                exit(-1);
        }

        s = initSocketS(port, &cliente);
        if (s == -1)
        {
                printf("Error - En la funcion initSocketS\n");
                exit(-1);
        }

        init_allegro();

        for (i = 0; i < 10; i++) //Como tengo 10 zonas hago 10 conexiones
        {
                printf("Esperando conexiones...\n");

                n_sock = accept(s, (struct sockaddr *)&cliente, &l_cliente);
                if (n_sock < 0)
                {
                        perror("Al aceptar el cliente");
                        return -1;
                }
                else
                {
                        //Seteo en 0 datos que requieren usarse en todas las iteraciones
                        memset(prom, 0, sizeof(prom));

                        fp = fopen("datos_recibidos.txt", "w+"); //Abro el archivo para leer y escribir. Si no existe lo crea y si existe lo sobreescribe
                        if (fp == NULL)
                        {
                                perror("Error - Al abrir el archivo");
                                exit(-1);
                        }

                        buffer = (char *)malloc(sizeof(char) * TAM); //Sabiendo el tamaño predeterminado de los archivos lo recibo con un buffer donde entren todos los datos
                        if (buffer == NULL)
                        {
                                perror("Error - Al asignar memoria");
                                exit(-1);
                        }

                        memset(buffer, 0, TAM);            //inicializo el buffer en 0
                        if (read(n_sock, buffer, TAM) < 0) //Lee los datos
                        {
                                perror("Error - Al leer el socket\t");
                                exit(-1);
                        }

                        fwrite(buffer, TAM, 1, fp); //Escribo todo en el file, para trabajar los datos es mas facil
                        rewind(fp);

                        free(buffer); //Como la memoria que pedi es muy grande, la libero ahora asi el programa puede seguir sin abarcar tanta memoria

                        /*TOMO DATOS y los almaceno en un vector de estructuras*/
                        cant = save_data(vec, fp); //Tomo todos los datos y los almaceno en un vector de estructuras

                        fclose(fp); //Una vez que tome todos los datos cierro el file

                        /*DETECTO LAS FLUCTUACIONES DE TENSION  y las guardo en el vector de struct registro*/
                        detectar_fluctuaciones(vec, cant, fp1);

                        /*SACO LOS PROMEDIOS DE TENSION X HORA */
                        prom_tension(prom, vec, cant);

                        //Hago el grafico
                        grafico(prom, vec[0]->area);

                        for (j = 0; j < CANT; j++) //Libero las struct pero no el vector de pointer a struct
                        {
                                free(vec[j]);
                        }
                        close(n_sock);
                        printf("Conexion terminada\n");
                }
        }
        fclose(fp1);
        shutdown_allegro();
        return 0;
}