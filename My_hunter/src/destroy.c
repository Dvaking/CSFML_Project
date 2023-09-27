/*
** EPITECH PROJECT, 2022
** destroy
** File description:
** destroy all sf
*/

#include <SFML/Graphics.h>

#include "proto.h"
#include "struct.h"

void destroy_text_sprite(sfTexture **texture, sfSprite **sprite, \
sfTexture **texture2, sfSprite **wallpaper)
{
    sfTexture_destroy(*texture2);
    sfTexture_destroy(*texture);
    sfSprite_destroy(*sprite);
    sfSprite_destroy(*wallpaper);
}

void destroy_time_stat(time_val_t *clock, stats_t *stat)
{
    sfClock_destroy(clock->clock);
    free(clock);
    free(stat);
}

void destroy_text_fond(sfText **text, sfFont **font)
{
    sfText_destroy(*text);
    sfFont_destroy(*font);
}
