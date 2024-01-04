#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#define width 1280
#define height 720

#define cantdivx 10 // cantidad de barras (y de divisiones del eje y, se pueden separar estas cosas)
#define cantdivy 5

int main()
{
        unsigned int i;

        char display_on = 1;

        char text[4];

        float porcentajes[cantdivx] = {0.24, 0.67, 0.02, 0.78, 0.98, 0.33, 0.61, 0.12, 0.5, 0.24}; //los porcentajes de qué tanto de todo el recorrido del eje y tengo que llenar con la barra

        al_init();                  // inicia allegro
        al_init_primitives_addon(); // inicia primitivas
        al_init_font_addon();

        al_set_new_display_refresh_rate(60);                      // tasa de refresco de la pantalla, innecesario
        ALLEGRO_DISPLAY *disp = al_create_display(width, height); // crea un display dentro del GUI del tamaño que le indiques (en nuestro caso x terminal)

        ALLEGRO_FONT *font = al_create_builtin_font(); // uso fuente predeterminada

        ALLEGRO_COLOR white = al_map_rgb(255, 255, 255); // guarda un color en rgb en una variable
        ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);

        ALLEGRO_COLOR bars[cantdivx]; // color rgb + gamma (por eso está transparente)

        for (i = 0; i < cantdivx; i++)
        {
                bars[i] = al_map_rgba(200, 0, 50, 100+(155 * porcentajes[i]));
        }

        al_clear_to_color(white); // limpia la pantalla y la setea de este color

        al_draw_line(50, (height - 100), (width - 50), (height - 100), black, 1); // x axis
        al_draw_line(100, 50, 100, (height - 50), black, 1);                      // y axis

        for (i = 0; i < cantdivx; i++)
        {
                al_draw_line(100 + (((width - 150) / (cantdivx + 1)) * (i + 1)), (height - 100) - 10, 100 + (((width - 150) / (cantdivx + 1)) * (i + 1)), (height - 100) + 10, black, 1); // x divs

                sprintf(text, "%d", (i + 1));

                al_draw_text(font, black, 100 + (((width - 150) / (cantdivx + 1)) * (i + 1)), (height - 75), ALLEGRO_ALIGN_CENTRE, text);

                al_draw_filled_rectangle(100 + (((width - 150) / (cantdivx + 1)) * (i + 1)) - ((width - 150) / (3 * cantdivx)), (height - 100), 100 + (((width - 150) / (cantdivx + 1)) * (i + 1)) + ((width - 150) / (3 * cantdivx)), (int)((height - 100) - (porcentajes[i] * (height - 150))), bars[i]); // barras
        }

        for (i = 0; i < cantdivy; i++)
        {
                al_draw_line(90, (height - 100) - (((height - 150) / cantdivy) * (i + 1)), 110, (height - 100) - (((height - 150) / cantdivy) * (i + 1)), black, 1); // y divs

                sprintf(text, "%d", (i + 1) * (100 / cantdivy));

                al_draw_text(font, black, 50, (height - 100) - (((height - 150) / cantdivy) * (i + 1)) - (al_get_font_line_height(font) / 2), ALLEGRO_ALIGN_CENTRE, text); // imprimo texto a la altura de las líneas de y
        }

        al_flip_display(); // invierte el display, ponganlo porque sino no se vé y por esto estaba puteando yo

        while (display_on) // si las barras no se mueven el while no es necesario, pero nos queremos mantener dentro del programa corriendo sin hacer las funciones de cierre de allegro por una cuestión lógica
        {
                sleep(1000); // menos del tiempo que se espera para lograr 60 frames, no quiero estar haciendo esto todo el tiempo porque parto la compu, si las barras no se mueven tranquilamente puede ser sleep(1)
        }

        al_shutdown_primitives_addon(); // cierra los primitivos (rectas, rectángulos)
        al_shutdown_font_addon();
        al_destroy_display(disp); // cierra el display
        al_destroy_font(font);    //cierra fuente

        return 0;
}