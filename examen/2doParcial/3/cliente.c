/*Deberá crear un tercer programa que enviará los archivos creados (stats_sistema_*) a las IPs descriptas en el archivo “sistemas_ips.txt”, 
este programa podrá manejar tantos hijos como la máquina soporte. Para poder averiguar la cantidad de CPUs de la máquina (y saber cuantos hijos puede levantar) 
utilice el archivo /proc/cpuinfo. Deberá recorrerlo buscando líneas que comiencen con “processor” y contarlas. La cantidad de líneas que encuentre serán la cantidad 
de núcleos.El programa actuará como cliente conectandose a las IPs server de la lista en “sistemas_ips.txt” usando el puerto 3000 vía TCP:a.Enviará primero un long 
con el tamaño del archivo.b.Luego enviará el contenido completo del archivo.c.Al finalizar se terminará la ejecución del hijo (de manera ordenada).Esto sucederá para 
cada IP del archivo hasta finalizar la lista y sin superar la cantidad de procesos simultáneos del sistema.*/


#include "my.h"

//Necesito una variable global si o si para saber cuantos hijos tengo al mismo tiempo
int hijos=0;
void interrupt (int signum);     //Tengo que declarar el handler aca porque necesito usar la variable global

int main (int argc, char **argv)
{
        FILE *fp;
        char *p=NULL, *file=NULL, *str=NULL, **ips=NULL;
        int i=0, s=0, nucleos=0, cant_ip=0;
        //Variables usadas en la conexion
        pid_t pid=0;
        int port = 3000;        //Puerto que voy a usar
        long int length=0;
        struct sockaddr_in server;    //struct para colocar datos en connect()

        if(argc !=2)
        {
                printf("./main <Archivo a enviar>");
                exit(-1);
        }

        //ME FIJO LA CANTIDAD DE NUCLEOS QUE TENGO
        fp=fopen("/proc/cpuinfo", "r");
        if(fp==NULL)
        {
                perror("Error - Al abrir el archivo");
                exit(-1);
        }

        fseek(fp, 0, SEEK_END);
        length=ftell(fp);
        rewind(fp);

        str= (char *) malloc( sizeof(char) * length);
        if(str == NULL)
        {
                perror("Error - Al asignar memoria\n");
                exit(-1);
        }

        fread(str, length, 1, fp);              //Leo todo el archivo

        p=strstr(str, "processor");

        for(i=1; p!=NULL; i++)                  //i=1 porque siempre tengo minimo un nucleo
        {
                p=strstr(p+1, "processor");      //Como tengo que buscar la misma palabra varias veces, si no hago que su puntero lo sobrepase me va a volver a encontrar lo mismo
        }
        
        nucleos=i;

        fclose(fp);             //Cierro este file para poder abrir otro

        //ME FIJO LAS IP
        fp=fopen("sistemas_ips.txt", "r");
        if(fp==NULL)
        {
                perror("Error - Al abrir el archivo");
                exit(-1);
        }

        fseek(fp, 0, SEEK_END);
        cant_ip=ftell(fp)/(sizeof(char) *15);   //(Me fijo cuantas ips tengo, asumo que son del tipo xxx.xxx.xxx.xxx)
        rewind(fp);

        ips=(char **)malloc( sizeof(char *) * cant_ip);         //Asigno memoria para guardar las ip
        if(ips==NULL)
        {
                perror("Error - Al asignar memoria\n");
                exit(-1);
        }

        for(i=0; i<cant_ip; i++)
        {
                ips[i]=(char *) malloc(sizeof(char) * 16);      //15 caracteres + NULL;
                fscanf(fp, "%s", ips[i]);
        }

        fclose(fp);

        //CONEXION

        for(i=0; i<cant_ip; i++)        //Hago tantas conexiones como cantidad de ips tenga
        {
                while(nucleos==hijos)           //mientras que haya igual cantidad de hijos que de nucleos voy a esperar a que se libere alguno, espero al signal handler
                {
                        usleep(1000);
                }

                hijos++;
                pid=fork();
                if(pid < 0)
                {
                        perror("Error - En el fork\n");
                        exit(-1);
                }
                else if(pid == 0) //PROCESO HIJO
                {
                        s=initSocketC(port, ips[i], &server);   //En cada iteracion agarro un ip e inicio una conexion, siempre y cuando tenga nucleos>hijos
                        if(s < 0)
                        {
                                printf("Error - En la funcion initScocketC\n");
                                exit(-1);
                        }

                        if(connect (s, (struct sockaddr*) &server, sizeof(server) ) <0)
                        {
                                perror("Al conectar\n");
                                exit(-1);
                        }

                        //Mando archivos
                        fp=fopen(*(argv +1), "r");
                        if(fp==NULL)
                        {
                                perror("Error al abrir el archivo\t");
                                exit(-1);
                        }

                        fseek(fp, 0, SEEK_END);
                        length=ftell(fp);
                        rewind(fp);

                        if( write(s, &length, sizeof(long int)) <0)
                        {
                                perror("Error - Al escribir en el socket\t");
                                exit(-1);
                        }

                        file=(char *) malloc(sizeof(char) * length);
                        if(file ==NULL)
                        {         
                                perror("Error - Al asignar memoria\n");
                                exit(-1);
                        }

                        fread(file, length, 1, fp);     //Leo todo el file

                        if( write(s, file, length ) <0)
                        {
                                perror("Error - Al escribir en el socket\t");
                                exit(-1);
                        }

                        free(file);
                        fclose(fp);
                        close(s);
                        return 0;
                }
                else    //PROCESE PADRE
                {
                        signal(SIGCHLD, interrupt);
                }
        }

        for(i=0; i<cant_ip; i++)
        {
                free(ips[i]);
        }
        free(ips);
        free(str);

        return 0;
}

void interrupt (int signum)             //Funcion de interrupcion
{
        signal(SIGCHLD, interrupt);     //Reseteo la señal

        wait(NULL);     //Cierro al hijo correctamente
        hijos--;        //Decremento la cantidad de hijos porque uno termino
}