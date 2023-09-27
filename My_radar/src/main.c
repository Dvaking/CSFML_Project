/*
** EPITECH PROJECT, 2022
** My_radar
** File description:
** graphical project
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

#include "proto.h"
#include "data_center.h"
#include "graphical.h"

static int my_radar_sub(sfRenderWindow **wnd, sprite_t *all_sprite, \
number_tower_plane_t *data)
{
    all_sprite->hitbox_visibility = 1;
    all_sprite->sprite_visibility = 1;
    data->pointer_plane = 0;
    all_sprite->clock = sfClock_create();
    for (int i = 0; data->tower > i; i += 1){
        sfSprite_setPosition(all_sprite->tower[i].sprite, \
        (sfVector2f){all_sprite->tower[i].x, all_sprite->tower[i].y});
    }
    while (sfRenderWindow_isOpen(*wnd)){
        sfRenderWindow_clear(*wnd, sfBlack);
        analyse_events(all_sprite, data, *wnd);
        if (display_windows(*wnd, all_sprite, data) == 1)
            return 0;
        sfRenderWindow_display(*wnd);
    }
}

static int my_radar(char **av)
{
    sfRenderWindow *wnd = create_windows(1920, 1080);
    texture_t *all_texture = malloc(sizeof(texture_t));
    sprite_t *all_sprite = malloc(sizeof(sprite_t));
    number_tower_plane_t *data = malloc(sizeof(number_tower_plane_t));
    data->pointer_plane = 0;
    how_many_tower_plane(data, av);
    if (texture_load(all_texture, wnd) == 84 || \
sprite_load(all_sprite, all_texture, data) == 84){
        destroy_texture_sprite_data_wnd(all_texture, all_sprite, data, wnd);
        return 84;
    }
    file_data_save(all_sprite, data, av);
    for (int i = 0; data->plane > i; i += 1){
        all_sprite->plane[i].invisible = 0;
        sfSprite_setPosition(all_sprite->plane[i].sprite, \
        (sfVector2f){all_sprite->plane[i].x, all_sprite->plane[i].y});
        sfSprite_setOrigin(all_sprite->plane[i].sprite, (sfVector2f){10, 10});
    }
    my_radar_sub(&wnd, all_sprite, data);
    destroy_texture_sprite_data_wnd(all_texture, all_sprite, data, wnd);
}

int main(int argc, char **argv, char *const *env)
{
    if (error_env(argc, argv, env) == 0) {
        return 84;
    }
    if (argc > 2) {
        return 84;
    }
    if (argv[1][0] == '-') {
        if (help(argc, argv) == 84){
            return 84;
        }
    } else if (check_file(argv) == 84) {
        return 84;
    } else if (my_radar(argv) == 84) {
        return 84;
    }
    return 0;
}
