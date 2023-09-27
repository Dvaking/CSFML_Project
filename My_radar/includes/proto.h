/*
** EPITECH PROJECT, 2022
** proto
** File description:
** proto
*/

#ifndef PROTO_H
    #define PROTO_H

    #define AIRCRAFT "picture/plane.png"
    #define TOWER "picture/tower.png"
    #define WALLPAPER "picture/wallpaper.jpg"

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>

    #include "data_center.h"
    #include "graphical.h"

            /* proto program */

        /* toolbox/ */
    int help(int ac, char **av);
    void destroy_texture_sprite_data_wnd(texture_t *texture, sprite_t *sprite,\
    number_tower_plane_t *data, sfRenderWindow *wnd);

        /* check_error/ */
    int error_env(int argc, char *const *argv,  char *const *env);
    int check_texture(texture_t *texture, sfRenderWindow *wnd);
    int check_sprite(sprite_t *sprite, number_tower_plane_t *data);
    int check_open_file(FILE *file);

        /* graphile/ */
    int texture_load(texture_t *all_texture, sfRenderWindow *wnd);
    void move_plane(sprite_t *sprite, number_tower_plane_t *data, int i);
    int sprite_load(sprite_t *all_sprite, texture_t *all_texture,\
    number_tower_plane_t *data);

    int display_windows(sfRenderWindow *window, sprite_t *all_sprite, \
    number_tower_plane_t *data);

    int display_sprite(sprite_t *sprite, number_tower_plane_t *data,\
    sfRenderWindow *window, int i);

    sfRenderWindow *create_windows(int x, int y);
    void analyse_events(sprite_t *sprite, number_tower_plane_t *data, \
    sfRenderWindow *wnd);
    sfRectangleShape *creat_square(sprite_t *all_sprite, int i);
    sfCircleShape *create_circle(sprite_t *all_sprite, int i);
    void display_square(sprite_t *all_sprite, sfRenderWindow *window, int i);
    void display_crcl(sprite_t *all_sprite, sfRenderWindow *window, int i);

        /* file/ */
    int check_file(char **av);
    int how_many_tower_plane(number_tower_plane_t *data, char **av);
    int file_data_save(sprite_t *all_sprite, number_tower_plane_t *data,\
    char **av);


#endif /* !PROTO_H */
