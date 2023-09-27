/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-marc.mendia
** File description:
** sprite
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "graphical.h"
#include "data_center.h"
#include "proto_lib.h"
#include "proto.h"

int sprite_load(sprite_t *all_sprite, texture_t *all_texture,\
number_tower_plane_t *data)
{
    all_sprite->plane = malloc(sizeof(plane_data_t) * data->plane);
    all_sprite->tower = malloc(sizeof(tower_data_t) * data->tower);
    for (int i = 0; i < data->plane; i += 1){
        all_sprite->plane[i].sprite = sfSprite_create();
        sfSprite_setTexture(all_sprite->plane[i].sprite, all_texture->plane, \
        sfFalse);
    }
    for (int i = 0; i < data->tower; i += 1){
        all_sprite->tower[i].sprite = sfSprite_create();
        sfSprite_setTexture(all_sprite->tower[i].sprite, all_texture->tower, \
        sfFalse);
    }
    all_sprite->wallpaper = sfSprite_create();
    sfSprite_setTexture(all_sprite->wallpaper, all_texture->wallpaper, \
    sfFalse);
    if (check_sprite(all_sprite, data) == 84)
        return 84;
}

static void take_vecteur(sprite_t *sprite, move_plane_t *move_plane, int i)
{
    float distance = sqrt((sprite->plane[i].end_x - sprite->plane[i].x) *
    (sprite->plane[i].end_x - sprite->plane[i].x) + \
    (sprite->plane[i].end_y - sprite->plane[i].y) *
    (sprite->plane[i].end_y - sprite->plane[i].y));
    move_plane->vecteur_x = (sprite->plane[i].end_x - sprite->plane[i].x)
/ distance;
    move_plane->vecteur_y = (sprite->plane[i].end_y - sprite->plane[i].y)
/ distance;
}

void move_plane(sprite_t *sprite, number_tower_plane_t *data, int i)
{
    move_plane_t *move_plane = malloc(sizeof(move_plane_t));
    take_vecteur(sprite, move_plane, i);
    if (sfClock_getElapsedTime(sprite->clock).microseconds / 1000000.0 >
        sprite->plane[i].time){
        sfSprite_move(sprite->plane[i].sprite, \
        (sfVector2f){move_plane->vecteur_x, move_plane->vecteur_y});
        }
    if ((sprite->plane[i].x == sprite->plane[i].end_x) && (sprite->plane[i].y
== sprite->plane[i].end_y)){
        sprite->plane[i].invisible = 1;
    }
    free(move_plane);
}

int display_sprite(sprite_t *sprite, number_tower_plane_t *data,\
sfRenderWindow *window, int i)
{
    if (i < data->tower)
        sfRenderWindow_drawSprite(window, sprite->tower[i].sprite, NULL);
    if (i < data->plane){
        if (sprite->plane[i].invisible == 0 &&
        sfClock_getElapsedTime(sprite->clock).microseconds / 1000000.0 >
        sprite->plane[i].time){
            sfRenderWindow_drawSprite(window, sprite->plane[i].sprite, NULL);
        }
        if (sprite->plane[i].invisible == 1){
            sprite->plane[i].invisible = 2;
            data->pointer_plane += 1;
        }
    }
}
