/*
** EPITECH PROJECT, 2022
** interaction
** File description:
** check teh interaction with the duck
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

#include "proto.h"

static void interaction_sub(stats_t *stat)
{
    if (stat->scale > 1.2){
        stat->scale -= 0.2;
    }
    if (stat->scale > 1.5 && stat->scale < 2){
        stat->speed += 1.0;
    }
    if (stat->scale > 0.8 && stat->scale < 1.5){
        stat->speed += 0.5;
    }
    stat->score += 1;
}

void interaction(sfMouseButtonEvent button, sfSprite *sprite, stats_t *stat, \
sfText *text)
{
    int spawn = rand() % (458 - 0 + 1) + 458;
    float len = 56;
    int sprite_post_x = sfSprite_getPosition(sprite).x;
    int sprite_post_y = sfSprite_getPosition(sprite).y;
    if (button.x > sprite_post_x && button.x < \
sprite_post_x + (56 * (stat->scale)) && button.y > sprite_post_y && \
button.y < sprite_post_y + (50 * (stat->scale))) {
        sfSprite_setPosition(sprite, (sfVector2f){0, spawn});
        interaction_sub(stat);
    } else {
        stat->scale = 2.8;
        sfSprite_setPosition(sprite, (sfVector2f){0, spawn});
        stat->speed = 8;
        stat->hp += 1;
    }
}
