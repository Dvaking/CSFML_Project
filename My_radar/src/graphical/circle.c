/*
** EPITECH PROJECT, 2022
** circle
** File description:
** all relative to the circle
*/

#include <SFML/Graphics.h>

#include "proto.h"
#include "graphical.h"

sfCircleShape *create_circle(sprite_t *all_sprite, int i)
{
    sfCircleShape *crcl = sfCircleShape_create();
    sfCircleShape_setRadius(crcl, all_sprite->tower[i].radius);
    sfCircleShape_setPosition(crcl, \
    (sfVector2f){all_sprite->tower[i].x - all_sprite->tower[i].radius + 30, \
    all_sprite->tower[i].y - all_sprite->tower[i].radius + 30});
    sfCircleShape_setOutlineThickness(crcl, 1);
    sfCircleShape_setOutlineColor(crcl, sfRed);
    sfCircleShape_setFillColor(crcl, sfTransparent);
    return crcl;
}

void display_crcl(sprite_t *all_sprite, sfRenderWindow *window, int i)
{
    all_sprite->tower[i].crcl = create_circle(all_sprite, i);
    sfRenderWindow_drawCircleShape(window, all_sprite->tower[i].crcl, NULL);
}
