/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-marc.mendia
** File description:
** how_many_tower_plane
*/

#include <stdio.h>
#include <stdlib.h>

#include "data_center.h"

int how_many_tower_plane(number_tower_plane_t *data, char **av)
{
    data->plane = 0;
    data->tower = 0;
    FILE *file;
    char **tab;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    file = fopen(av[1], "r");
    if (file == NULL)
        return 84;
    while ((nread = getline(&line, &len, file)) != -1) {
        if (line[0] == 'A')
            data->plane += 1;
        if (line[0] == 'T')
            data->tower += 1;
    }
    free(line);
    fclose(file);
}
