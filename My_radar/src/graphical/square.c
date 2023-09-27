/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-marc.mendia
** File description:
** hitbox
*/

#include <SFML/Graphics.h>

#include "graphical.h"
#include "proto.h"

sfRectangleShape *creat_square(sprite_t *all_sprite, int i)
{
    sfRectangleShape *square = sfRectangleShape_create();
    sfRectangleShape_setPosition(square, \
    (sfVector2f){all_sprite->plane[i].x - 10, all_sprite->plane[i].y - 10});
    sfRectangleShape_setSize(square, (sfVector2f){20, 20});
    sfRectangleShape_setOutlineThickness(square, 1);
    sfRectangleShape_setFillColor(square, sfTransparent);
    sfRectangleShape_setOutlineColor(square, sfWhite);
    return square;
}

void display_square(sprite_t *all_sprite, sfRenderWindow *window, int i)
{
    if (all_sprite->plane[i].invisible == 0 &&
    sfClock_getElapsedTime(all_sprite->clock).microseconds / 1000000.0 >
    all_sprite->plane[i].time){
        all_sprite->plane[i].square = creat_square(all_sprite, i);
        sfRenderWindow_drawRectangleShape(window, all_sprite->plane[i].square\
        , NULL);
    }
}
