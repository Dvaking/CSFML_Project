/*
** EPITECH PROJECT, 2022
** struct
** File description:
** struct
*/

#include <SFML/Graphics.h>

#ifndef STRUCT_H
    #define STRUCT_H

    typedef struct stats {
        float speed;
        float scale;
        int hp;
        int score;
        int score_max;
    } stats_t;

    typedef struct time_val {
        sfClock *clock;
        sfTime time;
        float seconds;
    } time_val_t;

#endif /* !STRUCT_H */
