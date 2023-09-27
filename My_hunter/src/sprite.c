/*
** EPITECH PROJECT, 2022
** sprite
** File description:
** create sprite
*/

#include <SFML/Graphics.h>

#include "proto.h"
#include "struct.h"

sfIntRect square(sfIntRect *rect)
{
    rect->top = 356;
    rect->left = 0;
    rect->width = 80;
    rect->height = 56;
}

sfIntRect move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left != max_value) {
        rect->left += offset;
    } else {
        rect->left = 0;
    }
}

void sprite_action(sfSprite *sprite, stats_t *stat)
{
    int spawn = rand() % (458 - 0 + 1) + 458;
    int sprite_x = sfSprite_getPosition(sprite).x;
    if (sprite_x > 1600) {
        stat->scale = 2.8;
        stat->speed = 8;
        stat->hp += 1;
        sfSprite_setPosition(sprite, (sfVector2f){0, spawn});
    }
    if (stat->scale > 0.8 && stat->scale < 2) {
        sfSprite_move(sprite, (sfVector2f){stat->speed, 0});
    } else {
        sfSprite_move(sprite, (sfVector2f){8, 0});
    }
}
