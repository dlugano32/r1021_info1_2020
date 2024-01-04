#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#define width 1280
#define height 720

#define cantdivx 24
#define cantdivy 30

int makeGraph(float *porcentajes, char *zone)
{
        unsigned int i;

        char *filename;

        ALLEGRO_COLOR bars[cantdivx];
        ALLEGRO_COLOR white;
        ALLEGRO_COLOR black;

        ALLEGRO_DISPLAY *disp;

        ALLEGRO_FONT *font;

        al_init();
        al_init_primitives_addon();
        al_init_font_addon();
        al_init_image_addon();

        disp = al_create_display(width, height);
        if (disp == NULL)
        {
                perror("Error obteniendo interfaz gráfica.\n");
        }

        font = al_create_builtin_font();
        if (font == NULL)
        {
                perror("Error obteniendo fuente.\n");
        }

        white = al_map_rgb(255, 255, 255);
        black = al_map_rgb(0, 0, 0);

        for (i = 0; i < cantdivx; i++)
        {
                bars[i] = al_map_rgba(200, 0, 50, 100 + (155 * porcentajes[i]));
        }

        filename = (char *)malloc(sizeof("graph") + sizeof(zone) + sizeof(".png") + 1);
        if (filename == NULL)
        {
                perror("Error reservando memoria.\n");
        }

        al_clear_to_color(white);

        al_draw_line(90, (height - 100), (width - 50), (height - 100), black, 1);
        al_draw_line(100, 50, 100, (height - 90), black, 1);

        al_draw_textf(font, black, width - 75, 25, ALLEGRO_ALIGN_CENTRE, "Zona %d", atoi(zone));

        for (i = 0; i < cantdivx; i++)
        {
                al_draw_line(100 + (((width - 150) / (cantdivx + 1)) * (i + 1)), (height - 100) - 10, 100 + (((width - 150) / (cantdivx + 1)) * (i + 1)), (height - 100) + 10, black, 1);

                al_draw_textf(font, black, 100 + (((width - 150) / (cantdivx + 1)) * (i + 1)), (height - 75), ALLEGRO_ALIGN_CENTRE, "%d", i);

                al_draw_filled_rectangle(100 + (((width - 150) / (cantdivx + 1)) * (i + 1)) - ((width - 150) / (3 * cantdivx)), (height - 100), 100 + (((width - 150) / (cantdivx + 1)) * (i + 1)) + ((width - 150) / (3 * cantdivx)), (int)((height - 100) - (porcentajes[i] * (height - 150))), bars[i]);
        }

        for (i = 0; i <= cantdivy; i++)
        {
                al_draw_line(90, (height - 100) - (((height - 150) / cantdivy) * i), 110, (height - 100) - (((height - 150) / cantdivy) * i), black, 1);

                al_draw_textf(font, black, 50, (height - 100) - (((height - 150) / cantdivy) * i) - (al_get_font_line_height(font) / 2), ALLEGRO_ALIGN_CENTRE, "%d", 175 + (i * (90 / cantdivy)));
        }

        sprintf(filename, "graph%s.png", zone);

        if (al_save_bitmap(filename, al_get_backbuffer(disp)) == 0)
        {
                perror("Error imprimiendo gráfico de salida.\n");
                exit(-1);
        }

        free(filename);

        al_shutdown_primitives_addon();
        al_shutdown_image_addon();
        al_shutdown_font_addon();
        al_destroy_display(disp);
        al_destroy_font(font);

        exit(0);
}

int main()
{
        float porcentajes[cantdivx] = {0.5, 0.6, 0.32};
        makeGraph(porcentajes, "3");
        return 0;
}