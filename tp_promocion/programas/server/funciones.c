#include "my.h"

int initSocketS(int port, struct sockaddr_in *local)
{
        int s=0;

        s= socket(AF_INET, SOCK_STREAM,0); 
        if(s<0)
        {
                perror("No se pudo crear el socket");
                return(-1);
        }

        /*CONFIGURO LA STRUCT sockaddr_in*/
        local->sin_family=AF_INET;
        local->sin_port=htons(port);   
        local->sin_addr.s_addr=htonl(INADDR_ANY);
        memset((void *) &(local->sin_zero), '\0', 8);

        /*PASO 2 :bind()*/
        if ( bind(s, (struct sockaddr *) local, sizeof( *local )) < 0)
        {
                perror("Asignando direccion");
                return(-1);
        }

        /*PASO 3: listen() y accept () */
        listen(s, 10);

        return s;
}

int save_data( struct medicion **vec, FILE *fp )
{
        int i=0, ret=0, cant=0, length=0;
        int iter=CANT;
        char str[50];
        struct medicion *aux=NULL;

        
        for(i=0; i<iter; i++)
        {
                aux=(struct medicion *)malloc(sizeof(struct medicion));
                if(aux==NULL)
                {
                        perror("Error - Al asignar memoria");
                        exit(-1);
                }

                //Tomo una linea del archivo
                fgets(str, 50, fp);
                length=strlen(str);
                length --;
                *(str + length) = '\0'; //le pongo null arriba del enter

                ret=fill_struct_med(aux, str);         //Relleno una struct y verifico si los datos son correctos

                if(ret==0)
                {
                        vec[i]=aux;
                        cant++; 
                }
                else
                {
                        iter--;         //Si hay algun dato mal tengo que hacer el for menos veces
                        i--;            //Si el dato esta mal, quiero sobreescribir la estructura donde estaba para no perder la continuidad de los datos
                        memset(str, 0, 50);     //Seteo en 0 str para volver a tomar otra linea del archivo
                }
        
                memset(str, 0, 50);     //Seteo en 0 str para volver a tomar otra linea del archivo
        }

        return cant;
}

int fill_struct_med(struct medicion *data, char *str)
{
        char  dato_fecha[5], *p=NULL;

        //Guardo la zona
        p=strtok(str,";");
        data->area=(char) atoi(p);

        //Guardo La fecha
        //año
        p=strtok(NULL,";");
        strncpy(dato_fecha, p, 4); 
        *(dato_fecha +4)='\0';
        data->f.anio=atoi(dato_fecha);
        memset(dato_fecha, 0, 5);         //inicializo el buffer en 0
        p+=4;       //Adelanto el puntero para tomar el mes

        //mes
        strncpy(dato_fecha, p, 2);
        data->f.mes=(char)atoi(dato_fecha);
        memset(dato_fecha, 0, 5);         //inicializo el buffer en 0
        p+=2;       //Adelanto el puntero para tomar el dia

        if(data->f.mes > 12 || data->f.mes < 1)
        {
                return -1;
        }

        //dia
        strncpy(dato_fecha, p, 2);
        data->f.dia=(char)atoi(dato_fecha);
        memset(dato_fecha, 0, 5);         //inicializo el buffer en 0

        if(data->f.dia > 31 || data->f.dia < 1)
        {
                return -1;
        }

        //Guardo la hora
        //horas
        p=strtok(NULL,";");
        strncpy(dato_fecha, p, 2);
        data->f.hora=(char)atoi(dato_fecha);
        memset(dato_fecha, 0, 5);         //inicializo el buffer en 0
        p+=2;

        if(data->f.hora > 23 || data->f.hora < 0)
        {
                return -1;
        }
        //min
        strncpy(dato_fecha, p, 2);
        data->f.min=(char)atoi(dato_fecha);
        memset(dato_fecha, 0, 5);         //inicializo el buffer en 0
        p+=2;

        if(data->f.min > 59 || data->f.min < 0)
        {
                return -1;
        }

        //seg
        strncpy(dato_fecha, p, 2);
        data->f.seg=(char)atoi(dato_fecha);
        memset(dato_fecha, 0, 5);         //inicializo el buffer en 0

        if(data->f.seg > 59 || data->f.seg < 0)
        {
                return -1;
        }
        
        //Tension
        p=strtok(NULL,";");
        data->volt=atoi(p);

        return 0;
}

void detectar_fluctuaciones(struct medicion **vec, int cant, FILE *fp)
{
        int i=0, j=0, k=0;
        int anom=0, T_max=0, T_min=0;
        struct anomalia **registro=NULL;

        registro=(struct anomalia **) malloc( sizeof(struct anomalia *));
        if(registro ==NULL)
        {
                perror("Error - Al asignar memoria\t");
                exit(-1);
        }

        for(i=0; i<24; i++)
        {
                for(j=0, anom=0, T_max=-1, T_min=300; j<cant; j++)
                {
                        if( vec[j]->f.hora== i )        //Analizo de a una franja horaria
                        {
                                if(vec[j]->volt > (220 + 220*0.1) || vec[j]->volt < (220 - 220*0.1) )
                                {
                                        anom++;

                                       if(vec[j]->volt > T_max)
                                        {
                                                T_max= vec[j]->volt;
                                        }

                                        if(vec[j]->volt < T_min)
                                        {
                                                T_min=vec[j]->volt;
                                        }
                                }
                        }
                }

                
                if(anom > (360*0.3) )   //Si mi cantidad de anomalias en la tension es mayor al 30% de 360 (cantidad de mediciones en una hora)
                {                
                        registro[k]=(struct anomalia *) malloc(sizeof(struct anomalia));
                        if(registro[k]==NULL)
                        {
                                perror("Error - Al asignar memoria\t");
                                exit(-1);
                        }

                        fill_struct_anom(registro[k], vec[i], i, T_max, T_min);         //Completo la struct

                        registro=(struct anomalia **) realloc(registro, sizeof(struct anomalia *) * (k+2));
                        if(registro == NULL)
                        {
                                perror("Error - Al asignar memoria\t");
                                exit(-1);
                        }
                        k++;
                }
        }

        //Guardo todo en el file
        for(i=0; i<k; i++)      //k es la cantidad de registros
        {       
                fprintf(fp, "Zona%d\tFecha: %d/%d/%d\t Desde %dhs a %dhs\nV_MAX=%d\tV_MIN%d \n", registro[i]->zona, registro[i]->anio, registro[i]->mes, registro[i]->dia, registro[i]->hora_in, registro[i]->hora_fin, registro[i]->T_max, registro[i]->T_min);
        }

        //Libero los recursos
        for(i=0; i<k ; i++)
        {
                free(registro[i]);
        }
        free(registro);
}

void fill_struct_anom(struct anomalia *registro, struct medicion *vec, int i, int T_max, int T_min)
{
        registro->zona=vec->area;
        registro->anio=vec->f.anio;
        registro->mes=vec->f.mes;
        registro->dia=vec->f.dia;
        registro->hora_in=i;
        registro->hora_fin=i+1;
        registro->T_max=T_max;
        registro->T_min=T_min;
}

void prom_tension(float *prom, struct medicion **vec, int cant)
{
        int i=0, j=0, cont_v=0;

        for(i=0; i<24; i++)
        {
                for(j=0, cont_v=0 ; j<cant; j++)
                {
                        if( vec[j]->f.hora== i ) 
                        {
                                cont_v=cont_v + vec[j]->volt;
                        }
                }

                prom[i]=(float)cont_v / 360.0;         //promedio de la tension x hora
        }

}

void init_allegro(void)
{
        //Inicializo el allegro
        al_init();
        al_init_primitives_addon();
        al_init_font_addon();
        al_init_image_addon();
        
}

void grafico (float *prom, int zona)      //Le meto un vector de floats con porcentajes y la cantidad de datos
{
        int i=0;
        char str[4];
        char str_zona[6];
        char *fileName=NULL;

        fileName= (char*) malloc( sizeof(char) * 15);     //graph_zonx.png+NULL
        if(fileName == NULL)
        {
                perror("Error - Al asignar memoria");
                exit(-1);
        }

        sprintf(fileName, "%s%d%s", "graph_zone", zona, ".png");
        
        ALLEGRO_DISPLAY *disp = al_create_display(width, height);       //Creo un display dentro de la interfaz grafica de la resolucion indicada
        ALLEGRO_FONT *font = al_create_builtin_font();          //Set fuente predeterminada
        ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);        //seteo un color a una variable
        ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
        ALLEGRO_COLOR orange = al_map_rgb(255, 165,0);        

        //Creo el grafico
        al_clear_to_color(white);       //Pongo el fondo blanco

        al_draw_line(40, (height-40), (width-20), (height-40), black, 3);     //Dibujo el eje x
        al_draw_line(50, (height-30), 50, 30, black, 3);          //Dibujo el eje y
        al_draw_line(50, (height - 246), (width - 20), (height - 246), black, 1);               //Referencia en 220
        
        al_draw_text(font, black, 25, (height - 246) - (((height - 70) / ref_y )* i ) - (al_get_font_line_height(font) / 2), ALLEGRO_ALIGN_CENTRE, "220");    //le agrego su referencia correspondiente
        al_draw_text(font, black, 25, (height - 40) - (((height - 70) / ref_y )* i ) - (al_get_font_line_height(font) / 2), ALLEGRO_ALIGN_CENTRE, "175");    //le agrego su referencia correspondiente
        sprintf(str_zona, "%s%d", "Zona", zona);
        al_draw_text(font, black, width - 40, 40 , ALLEGRO_ALIGN_CENTRE, str_zona);   

        //Paso los promedios a porcentajes respecto de la escala del grafico
        for(i=0; i<BARRAS; i++)
        {
                //aux=(prom[i]-175) * (1/90);             //Para que me queden los promedios en el formato 10%=0.1        
                //printf("prom[%d]=%f\n", i, prom[i]);
                prom[i] = (prom[i] - 175.0)*(1.0/90.0);
                printf("%f\n", prom[i]);

        }

        //Dibujo las barras del grafico
        for(i=0; i<BARRAS; i++)
        {
                al_draw_filled_rectangle( 40 + ( ( (width -70) / (BARRAS + 1) ) * (i +1) ) - ((width - 70) / (5 * BARRAS)) , (height -40), 40 + ( ( (width -70) / (BARRAS + 1) ) * (i +1) ) + ((width - 70) / (5 * BARRAS)) , (int) ( (height-40) - ( prom [i] * (height - 70) ) ), orange);    //Dibujo las barras
                sprintf(str, "%d", i );      
                al_draw_text(font, black, 40 + ( ( (width -70) / (BARRAS + 1) ) * (i +1) ) , (height - 30), ALLEGRO_ALIGN_CENTRE, str);   //Imprime el mensaje de la barra en un string
        }

        al_flip_display();

        if (al_save_bitmap(fileName, al_get_backbuffer(disp)) == 0)
        {
                perror("Error - Sacando screenshot al grafico\t");
                exit(-1);
        }

        free(fileName);

        al_destroy_display(disp);
        al_destroy_font(font);

}

void shutdown_allegro(void)
{
        //Libero recursos
        al_shutdown_primitives_addon();
        al_shutdown_image_addon();
        al_shutdown_font_addon();
}