/*
** EPITECH PROJECT, 2019
** my_str_isnum.c
** File description:
** Return 1 if the string is all numeric, 0 otherwise
*/

#include <stdbool.h>

bool my_str_isnum(char const *str)
{
    unsigned int i = 0;

    while (str[0] == ' ')
        str++;
    if (str[0] == '-' && str[1])
        i = i + 1;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
        i = i + 1;
    }
    return (true);
}
