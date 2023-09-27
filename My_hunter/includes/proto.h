/*
** EPITECH PROJECT, 2022
** proto
** File description:
** my proto
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

#include "struct.h"

#ifndef PROTO_H
    #define PROTO_H

        /* proto lib */
    int my_putstr(char const *str);
    int my_strncmp(char const *s1, char const *s2, int n);

        /* proto programme */
    /* windows.c */
    sfRenderWindow *create_windows(sfRenderWindow *windows, int x, int y);
    void display_windows(sfRenderWindow *windows, sfSprite *sprite, \
    sfSprite *wallpaper, sfText *text);
    void interaction(sfMouseButtonEvent button, sfSprite *sprite, stats_t \
    *stat, sfText *text);
    void display_hp_score(stats_t *stat, sfText *text);

    /* sprite.c */
    void sprite_action(sfSprite *sprite, stats_t *stat);
    sfIntRect move_rect(sfIntRect *rect, int offset, int max_value);
    void analyse_events(sfRenderWindow *window, sfSprite *sprite, stats_t \
    *stat, sfText *text);
    sfIntRect square(sfIntRect *rect);

    /* destroy && other*/
    void init_value_str(stats_t *stat, char *str);
    int protection_sub(sfTexture **texture, sfTexture **texture2, sfFont \
    **font);
    void destroy_text_fond(sfText **text, sfFont **font);
    void destroy_time_stat(time_val_t *clock, stats_t *stat);
    void destroy_text_sprite(sfTexture **texture, sfSprite **sprite, \
    sfTexture **texture2, sfSprite **wallpaper);
    int help(int ac, char **av);
    int protection(int argc, char *const *argv,  char *const *env);

#endif /* !PROTO_H */
