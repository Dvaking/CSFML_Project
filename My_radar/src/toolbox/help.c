/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-marc.mendia
** File description:
** help
*/

#include "proto_lib.h"

int help(int ac, char **av)
{
    if (av[1][0] == '-') {
        if (av[1][1] == 'h', av[1][2] == '\0'){
            my_putstr("Air traffic simulation panel\n\nUSAGE\n ./my_radar \
[OPTIONS] path_to_script\n  path_to_script   The path to the script file.\n\n\
OPTIONS\n -h\tprint the usage and quit.\n\nUSER INTERACTIONS\n L key\t\
enable/disable hitboxes and areas.\n S key\tenable/disable sprites.\n");
        } else {
            my_putstr("Flag invalid\n");
            return 84;
        }
    }
    return 0;
}
