/*
** EPITECH PROJECT, 2022
** data_center
** File description:
** data_center
*/

#ifndef DATA_CENTER_H_H
    #define DATA_CENTER_H_H
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    typedef struct plane_data {
        sfSprite *sprite;
        sfRectangleShape *square;
        int x;
        int y;
        int end_x;
        int end_y;
        int speed;
        int invisible;
        int time;
    } plane_data_t;

    typedef struct tower_data {
        sfSprite *sprite;
        sfCircleShape *crcl;
        int x;
        int y;
        int radius;
    } tower_data_t;

    typedef struct number_tower_plane {
        int tower;
        int plane;
        int pointer_tower;
        int pointer_plane;
    } number_tower_plane_t;

    typedef struct move_plane {
        float vecteur_x;
        float vecteur_y;
    } move_plane_t;


#endif /* !DATA_CENTER_H_H */
