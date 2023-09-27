/*
** EPITECH PROJECT, 2022
** windowd
** File description:
** all relative to the windows
*/

#include <SFML/Graphics.h>

#include "proto.h"
#include "data_center.h"
#include "graphical.h"

static void check_modification_display(sprite_t *sprite, \
number_tower_plane_t *data, sfEvent *event)
{
    if (event->key.code == sfKeyL){
        if (sprite->hitbox_visibility == 0) {
            sprite->hitbox_visibility = 1;
        } else {
            sprite->hitbox_visibility = 0;
        }
    }
    if (event->key.code == sfKeyS){
        if (sprite->sprite_visibility == 0) {
            sprite->sprite_visibility = 1;
        } else {
            sprite->sprite_visibility = 0;
        }
    }
}

void analyse_events(sprite_t *sprite, number_tower_plane_t *data, \
sfRenderWindow *wnd)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(wnd, &event)) {
        if (event.type == sfEvtClosed) {
            sfClock_destroy(sprite->clock);
            sfRenderWindow_close(wnd);
        }
        if (event.type == sfEvtKeyPressed) {
            check_modification_display(sprite, data, &event);
        }
    }
}

sfRenderWindow *create_windows(int x, int y)
{
    sfVideoMode mode = {x, y, 32};
    sfRenderWindow *wnd = sfRenderWindow_create(mode, "My_radar", \
sfClose, NULL);
    sfRenderWindow_setFramerateLimit(wnd, 60);
    return wnd;
}

int display_windows(sfRenderWindow *window, sprite_t *sprite, \
number_tower_plane_t *data)
{
    sfRenderWindow_drawSprite(window, sprite->wallpaper, NULL);
    for (int i = 0; i < data->plane; i += 1){
        sprite->plane[i].x = sfSprite_getPosition(sprite->plane[i].sprite).x;
        sprite->plane[i].y = sfSprite_getPosition(sprite->plane[i].sprite).y;
        move_plane(sprite, data, i);
        if (sprite->hitbox_visibility == 1)
            display_square(sprite, window, i);
        if (sprite->sprite_visibility == 1)
            display_sprite(sprite, data, window, i);
    }
    for (int i = 0; i < data->tower; i += 1){
        if (sprite->hitbox_visibility == 1)
            display_crcl(sprite, window, i);
        if (sprite->sprite_visibility == 1)
            display_sprite(sprite, data, window, i);
    }
    if (data->pointer_plane == data->plane)
        return 1;
    return 0;
}
