/*
** EPITECH PROJECT, 2022
** destroy
** File description:
** for destroy texture, windows etc..
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "graphical.h"
#include "data_center.h"

void destroy_texture_sprite_data_wnd_sub(texture_t *texture, \
sprite_t *sprite, number_tower_plane_t *data, sfRenderWindow *wnd)
{
    sfTexture_destroy(texture->wallpaper);
    sfTexture_destroy(texture->plane);
    sfTexture_destroy(texture->tower);
    sfRenderWindow_destroy(wnd);
    free(data);
    free(texture);
    free(sprite);
}

void destroy_texture_sprite_data_wnd(texture_t *texture, sprite_t *sprite, \
number_tower_plane_t *data, sfRenderWindow *wnd)
{
    for (int i = 0; i < data->plane; i += 1){
        sfSprite_destroy(sprite->plane[i].sprite);
        sfRectangleShape_destroy(sprite->plane[i].square);
    }
    for (int i = 0; i < data->tower; i += 1){
        sfSprite_destroy(sprite->tower[i].sprite);
        sfCircleShape_destroy(sprite->tower[i].crcl);
    }
    sfSprite_destroy(sprite->wallpaper);
    sfTexture_destroy(texture->wallpaper);
    sfTexture_destroy(texture->plane);
    sfTexture_destroy(texture->tower);
    sfRenderWindow_destroy(wnd);
    free(data);
    free(texture);
    free(sprite);
}
