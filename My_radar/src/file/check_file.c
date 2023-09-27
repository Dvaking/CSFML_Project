/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-marc.mendia
** File description:
** check_file
*/

#include <stdio.h>
#include <stdlib.h>

#include "proto_lib.h"
#include "proto.h"

static int check_tower(char *line)
{
    int count = 0;
    for (int i = 0; line[i] != '\0'; i += 1) {
        if (((line[i] > 'a' && line[i] < 'z') || \
(line[i] > 'A' && line[i] < 'Z') || (line[i] > '0' && line[i] < '9') \
) && (line[i + 1] == ' '))
        count += 1;
    }
    if (count > 4){
        return 1;
    }
    return 0;
}

static int check_plane(char *line)
{
    int count = 0;
    for (int i = 0; line[i] != '\0'; i += 1) {
        if (((line[i] > 'a' && line[i] < 'z') || \
(line[i] > 'A' && line[i] < 'Z') || (line[i] > '0' && line[i] < '9') \
) && (line[i + 1] == ' '))
        count += 1;
    }
    if (count > 7)
        return 1;
    return 0;
}

static int check_file_sub(char *line)
{
    int return_value = 0;
    if (line[0] == 'A')
        return_value = check_plane(line);
    if (line[0] == 'T')
        return_value = check_tower(line);
    if (line[0] != 'T' && line[0] != 'A' && return_value == 1)
        return 1;
    return return_value;
}

int check_file(char **av)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    file = fopen(av[1], "r");
    if (check_open_file(file) == 84)
        return 84;
    while ((nread = getline(&line, &len, file)) != -1) {
        if (check_file_sub(line) == 1)
            return 84;
        if (line[my_strlen(line) - 1] != '\n'){
            my_putstr("File invalide, please check info_file.legend\n");
            return 84;
        }
    }
    free(line);
    fclose(file);
    return 0;
}
