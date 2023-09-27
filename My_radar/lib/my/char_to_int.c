/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-marc.mendia
** File description:
** char_to_int
*/

int my_strlen(char const *str);

int char_to_int(char *str)
{
    int percent = 1;
    int nbr = 0;
    for (int count = my_strlen(str) - 1; count >= 0; count -= 1) {
        nbr += (str[count] - 48) * percent;
        percent *= 10;
    }
    return nbr;
}
