/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** A faire
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        my_putchar(str[i]);
        i = i + 1;
    }
    return (i);
}
