#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <unistd.h>

#define width 720       //Resolucion en pixeles 720x480
#define height 480
 
#define ref_y 9

void bargraph (float *data, int cant);

int main (void)
{
        float data[24]={0.2 , 0.5 , 0.1 , 0.75 , 0.88,0.2 , 0.4 , 0.1 , 0.75 , 1.00 ,0.2 , 0.4 , 0.1 , 0.75 , 0.88,0.2 , 0.4 , 0.1 , 0.75 , 0.88,0.2 , 0.4 , 0.1 , 0.83 };
        bargraph(data, 24);
        return 0;
}

void bargraph (float *data, int cant)      //Le meto un vector de floats con porcentajes y la cantidad de datos
{
        int i=0;
        char str[4];
        char zone[6];
        char *fileName=NULL;

        fileName= (char*) malloc( sizeof(char) * 15);     //graph_zonx.png+NULL
        if(fileName == NULL)
        {
                perror("Error - Al asignar memoria");
                exit(-1);
        }

        sprintf(fileName, "%s%d%s", "graph_zone", 0, ".png");
        
        //Inicializo el allegro
        al_init();
        al_init_primitives_addon();
        al_init_font_addon();
        al_init_image_addon();

        //Configuraciones
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
        sprintf(zone, "%s%d", "Zona", 0);
        al_draw_text(font, black, width - 40, 40 , ALLEGRO_ALIGN_CENTRE, zone);   
        //Dibujo las barras del grafico
        for(i=0; i<cant; i++)
        {
                al_draw_filled_rectangle( 40 + ( ( (width -70) / (cant + 1) ) * (i +1) ) - ((width - 70) / (5 * cant)) , (height -40), 40 + ( ( (width -70) / (cant + 1) ) * (i +1) ) + ((width - 70) / (5 * cant)) , (int) ( (height-40) - ( data [i] * (height - 70) ) ), orange);    //Dibujo las barras
                sprintf(str, "%d", i );      
                al_draw_text(font, black, 40 + ( ( (width -70) / (cant + 1) ) * (i +1) ) , (height - 30), ALLEGRO_ALIGN_CENTRE, str);   //Imprime el mensaje de la barra en un string
        }

        al_flip_display();

        if (al_save_bitmap(fileName, al_get_backbuffer(disp)) == 0)
        {
                perror("Error - Sacando screenshot al grafico\t");
                exit(-1);
        }

        free(fileName);

        //Libero recursos
        al_shutdown_primitives_addon();
        al_shutdown_image_addon();
        al_shutdown_font_addon();
        al_destroy_display(disp);
        al_destroy_font(font);

}