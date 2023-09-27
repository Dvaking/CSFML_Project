/*
** EPITECH PROJECT, 2022
** other
** File description:
** other fonction
*/

#include <string.h>

#include "proto.h"

int help(int ac, char **av)
{
    if (ac > 2) {
        return 84;
    }
    if (av[1][0] == '-') {
        if (av[1][1] == 'h', av[1][2] == '\0') {
            my_putstr("Ghost Hunt est un jeu où tu incarnes un membre de du \
célèbre groupe ghost buster, chasse les fantômes en clickant \
dessus avant qu'il quitte l'écran attention à ne pas les manquer \
sinon ils deviennent invisibles\n");
        } else {
            my_putstr("Flag invalid\n");
            return 84;
        }
    } else {
        my_putstr("Invalid Input\n");
    }
    return 0;
}

int protection_sub(sfTexture **texture, sfTexture **texture2, sfFont **font)
{
    if (*texture == NULL){
        return 84;
    }
    if (*texture2 == NULL){
        return 84;
    }
    if (*font == NULL) {
        return 84;
    }
    return 0;
}

int protection(int argc, char *const *argv,  char *const *env)
{
    int count = 0;
    int value = 0;
    while (env[count] != NULL) {
        if (my_strncmp(env[count], "DISPLAY=:0", 11) == 0)
            value = 1;
        count += 1;
    }
    return value;
}

void init_value_str_sub(stats_t *stat, char *str)
{
    int tempory = stat->score;
    int nbr = 0;
    for (int i = tempory; i > 0; i /= 10) {
        nbr += 1;
    }
    while (nbr > 0) {
        if (stat->score > 9){
            str[12 + nbr] = (tempory % 10) + '0';
            tempory /= 10;
        } else {
            str[13] = (tempory) + '0';
        }
        nbr -= 1;
    }
}

void init_value_str(stats_t *stat, char *str)
{
    int count = 5;
    str[0] = 'H';
    str[1] = 'P';
    str[2] = ':';
    str[3] = ' ';
    str[4] = (count - stat->hp) + '0';
    str[5] = '\n';
    str[6] = 'S';
    str[7] = 'C';
    str[8] = 'O';
    str[9] = 'R';
    str[10] = 'E';
    str[11] = ':';
    str[12] = ' ';
    if (stat->score == 0) {
        str[13] = '0';
    } else {
        init_value_str_sub(stat, str);
    }
}
