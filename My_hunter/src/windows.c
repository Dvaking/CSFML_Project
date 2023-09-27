/*
** EPITECH PROJECT, 2022
** create windows
** File description:
** fix taille de laa page
*/

#include <SFML/Graphics.h>

#include "proto.h"
#include "struct.h"

sfRenderWindow *create_windows(sfRenderWindow *windows, int x, int y)
{
    sfVideoMode mode = {x, y, 32};
    sfRenderWindow *wnd = sfRenderWindow_create(mode, "Ghost Hunt", \
sfClose, NULL);
    sfRenderWindow_setFramerateLimit(wnd, 60);
    return wnd;
}

void display_windows(sfRenderWindow *window, sfSprite *sprite, \
sfSprite *wallpaper, sfText *text)
{
    sfRenderWindow_drawSprite(window, wallpaper, NULL);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
}

void analyse_events(sfRenderWindow *window, sfSprite *sprite, stats_t *stat, \
sfText *text)
{
    sfEvent event;
    display_hp_score(stat, text);
    sfSprite_setScale(sprite,  (sfVector2f){stat->scale, stat->scale});
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            interaction(event.mouseButton, sprite, stat, text);
        }
    }
}

void display_hp_score(stats_t *stat, sfText *text)
{
    char *str = malloc(sizeof(char) * 17);
    str[17] = '\0';
    for (int i = 0; str[i] = '\0'; i += 1){}
    init_value_str(stat, str);
    sfText_setString(text, str);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){0,0});
    free (str);
}
