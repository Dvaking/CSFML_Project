/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-marc.mendia
** File description:
** file_data
*/

#include <stdlib.h>
#include <stdio.h>

#include "graphical.h"
#include "data_center.h"
#include "proto_lib.h"

static void assigne_value_tower(sprite_t *sprite, number_tower_plane_t *data,\
char **tab)
{
    int number = 0;
    number = char_to_int(tab[1]);
    sprite->tower[data->pointer_tower].x = number;
    number = char_to_int(tab[2]);
    sprite->tower[data->pointer_tower].y = number;
    number = char_to_int(tab[3]);
    sprite->tower[data->pointer_tower].radius = number;
}

static void assigne_value_plane(sprite_t *sprite, number_tower_plane_t *data,\
char **tab)
{
    int number = 0;
    number = char_to_int(tab[1]);
    sprite->plane[data->pointer_plane].x = number;
    number = char_to_int(tab[2]);
    sprite->plane[data->pointer_plane].y = number;
    number = char_to_int(tab[3]);
    sprite->plane[data->pointer_plane].end_x = number;
    number = char_to_int(tab[4]);
    sprite->plane[data->pointer_plane].end_y = number;
    number = char_to_int(tab[5]);
    sprite->plane[data->pointer_plane].speed = number;
    number = char_to_int(tab[6]);
    sprite->plane[data->pointer_plane].time = number;

}

static char *take_data(char *line, int *count)
{
    char *str;
    int nbr_cols = 0;
    int i = 0;
    if (line[*count] == ' '){
        while (line[*count] == ' ')
            *count += 1;
    }
    for (int i = *count; line[i] != ' '; i += 1)
        nbr_cols += 1;
    str = malloc(sizeof(char) * nbr_cols + 1);
    str[nbr_cols] = '\0';
    for (int i = 0; line[*count] != ' '; i += 1){
        str[i] = line[*count];
        *count += 1;
    }
    return str;
}

static int find_data(sprite_t *all_sprite, number_tower_plane_t *data,\
char **tab, char *line)
{
    int count = 0;
    if (line[0] == 'A'){
        tab = malloc(sizeof(char *) * 8);
        for (int i = 0; i < 7; i += 1)
            tab[i] = take_data(line, &count);
        assigne_value_plane(all_sprite, data, tab);
        data->pointer_plane += 1;
        free(tab);
    }
    if (line[0] == 'T') {
        tab = malloc(sizeof(char *) * 5);
        for (int i = 0; i < 4; i += 1)
            tab[i] = take_data(line, &count);
        assigne_value_tower(all_sprite, data, tab);
        data->pointer_tower += 1;
        free(tab);
    }
}

int file_data_save(sprite_t *all_sprite, number_tower_plane_t *data, char **av)
{
    FILE *file;
    char **tab;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    file = fopen(av[1], "r");
    if (file == NULL) {
        return 1;
    }
    while ((nread = getline(&line, &len, file)) != -1) {
        find_data(all_sprite, data, tab, line);
    }
    free(line);
    fclose(file);
    return 0;
}
