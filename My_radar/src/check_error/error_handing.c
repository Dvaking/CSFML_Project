/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-marc.mendia
** File description:
** error_environement
*/

#include <SFML/Graphics.h>
#include "stdio.h"

#include "proto_lib.h"
#include "proto.h"

int error_env(int argc, char *const *argv,  char *const *env)
{
    int count = 0;
    int value = 0;
    while (env[count] != NULL) {
        if (my_strncmp(env[count], "DISPLAY=:0", 11) == 0)
            value = 1;
        count += 1;
    }
    return value;
}

int check_texture(texture_t *texture, sfRenderWindow *wnd)
{
    if (wnd == NULL){
        return 84;
    }
    if (texture->wallpaper == NULL){
        return 84;
    }
    if (texture->tower == NULL){
        return 84;
    }
    if (texture->plane == NULL){
        return 84;
    }
    return 0;
}

int check_sprite(sprite_t *sprite, number_tower_plane_t *data)
{
    for (int i = 0; i < data->tower; i += 1){
        if (sprite->tower[i].sprite == NULL)
            return 84;
    }
    for (int i = 0; i < data->plane; i += 1){
        if (sprite->plane[i].sprite == NULL)
            return 84;
    }
    if (sprite->wallpaper == NULL)
        return 84;
    return 0;
}

int check_open_file(FILE *file)
{
    if (file == NULL){
        my_putstr("File invalide, please check info_file.legend\n");
        return 84;
    }
}
