/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-marc.mendia
** File description:
** texture
*/

#ifndef TEXTURE_H_
    #define TEXTURE_H_

    #include <SFML/Graphics.h>
    #include "data_center.h"

    typedef struct texture {
        sfTexture *plane;
        sfTexture *tower;
        sfTexture *wallpaper;
    } texture_t;

    typedef struct sprite {
        plane_data_t *plane;
        tower_data_t *tower;
        sfSprite *wallpaper;
        int hitbox_visibility;
        int sprite_visibility;
        sfClock *clock;
    } sprite_t;

#endif /* !TEXTURE_H_ */
