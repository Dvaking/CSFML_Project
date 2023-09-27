/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-marc.mendia
** File description:
** texture
*/

#include <SFML/Graphics.h>

#include "graphical.h"
#include "proto.h"

int texture_load(texture_t *all_texture, sfRenderWindow *wnd)
{
    all_texture->wallpaper = sfTexture_createFromFile(WALLPAPER, NULL);
    all_texture->plane = sfTexture_createFromFile(AIRCRAFT, NULL);
    all_texture->tower = sfTexture_createFromFile(TOWER, NULL);
    if (check_texture(all_texture, wnd) == 84){
        return 84;
    }
    return 0;
}
