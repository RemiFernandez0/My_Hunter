/*
** EPITECH PROJECT, 2022
** int_to_str
** File description:
** int_to_str
*/
#include <stdlib.h>

int my_countlen(int nb)
{
    int count = 0;
    while (nb >= 10) {
        count++;
        nb = nb / 10;
    }
    return count;
}

char * my_int_to_str(int nb)
{
    int count = my_countlen(nb);
    int count_base = count;
    char * str = malloc(sizeof(char) * count + 1);
    while (nb >= 10) {
        str[count] = 48 + nb % 10;
        count--;
        nb = nb / 10;
    }
    str[0] = 48 + nb % 10;
    str[count_base + 1] = '\0';
    return str;
}
