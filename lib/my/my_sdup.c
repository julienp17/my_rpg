/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_sdup
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

char *my_sdup(int nb_str, ...)
{
    va_list args;
    char *sdup = NULL;
    va_start(args, nb_str);

    sdup = my_strdup(va_arg(args, char *));
    for (int i = 1 ; i < nb_str ; i++)
        sdup = my_strdupcat(sdup, va_arg(args, char *));
    va_end(args);
    return (sdup);
}