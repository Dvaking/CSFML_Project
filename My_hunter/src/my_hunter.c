/*
** EPITECH PROJECT, 2022
** My_Hunter
** File description:
** Le meilleure projet au monde
** (en gros tu fait un dunk hunt)
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

#include "proto.h"
#include "struct.h"

static void my_hunter_ter(time_val_t *clock, sfIntRect *rect, sfSprite \
*sprite, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTextureRect(sprite, *rect);
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    if (clock->seconds > 0.119){
        sfClock_restart(clock->clock);
        move_rect(rect, 80, 240);
    }
}

static void my_hunter_sub(sfRenderWindow **window, sfSprite **sprite, \
sfSprite **wallpaper, sfText **text)
{
    stats_t *stat = malloc(sizeof(stats_t));
    time_val_t *clock = malloc(sizeof(time_val_t));
    stat->score = 0;
    clock->clock = sfClock_create();
    sfIntRect rect;
    stat->scale = 2.8;
    square(&rect);
    stat->speed = 8;
    sfSprite_setPosition(*sprite, (sfVector2f){0, 750});
    while (sfRenderWindow_isOpen(*window)) {
        analyse_events(*window, *sprite, stat, *text);
        my_hunter_ter(clock, &rect, *sprite, *window);
        sprite_action(*sprite, stat);
        if (stat->hp == 5){
            destroy_time_stat(clock, stat);
            return;
        }
        display_windows(*window, *sprite, *wallpaper, *text);
    }
    destroy_time_stat(clock, stat);
}

static int my_hunter(void)
{
    sfRenderWindow *windows = create_windows(windows, 1600, 1080);
    sfTexture *texture = sfTexture_createFromFile("ghost.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture2 = sfTexture_createFromFile("wallpaper.jpg", NULL);
    sfSprite *wallpaper = sfSprite_create();
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("pixel_coleco.otf");
    if (protection_sub(&texture, &texture2, &font) == 84) {
        return 84;
    }
    sfText_setFont(text, font);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTexture(wallpaper, texture2, sfFalse);
    my_hunter_sub(&windows, &sprite, &wallpaper, &text);
    destroy_text_sprite(&texture, &sprite, &texture2, &wallpaper);
    destroy_text_fond(&text, &font);
    sfRenderWindow_destroy(windows);
}

int main(int argc, char **argv, char *const *env)
{
    if (protection(argc, argv, env) == 0) {
        return 84;
    }
    if (argc > 1) {
        if (help(argc, argv) == 84){
            return 84;
        }
    } else if (my_hunter() == 84) {
        return 84;
    }
    return 0;
}
