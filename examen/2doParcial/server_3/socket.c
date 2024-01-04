#include "socket.h"

int initSocketS(char * port, struct sockaddr_in *local)
{
        int s=0, n_port=0;

        s= socket(AF_INET, SOCK_STREAM,0); 
        if(s<0)
        {
                perror("No se pudo crear el socket");
                exit(1);
        }

        /*CONFIGURO LA STRUCT sockaddr_in*/
        n_port=atoi(port);
        local->sin_family=AF_INET;
        local->sin_port=htons(n_port);   
        local->sin_addr.s_addr=htonl(INADDR_ANY);
        memset((void *) &(local->sin_zero), '\0', 8);

        /*PASO 2 :bind()*/
        if ( bind(s, (struct sockaddr *) local, sizeof( *local )) < 0)
        {
                perror("Asignando direccion");
                exit(1);
        }

        /*PASO 3: listen() y accept () */
        listen(s, SOMAXCONN);

        return s;
}

