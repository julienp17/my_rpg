/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** stat_get_str_by_enum
*/

#include <stdlib.h>
#include "stats.h"
#include "my.h"

char *stats_get_str_by_enum(int value)
{
    char const *stats_fields[] = {
        "Health", "Mana", "Atk", "Def", "Experience", NULL
    };

    for (int i = 0 ; stats_fields[i] ; i++)
        if (i == value)
            return (my_strdup(stats_fields[i]));
    return (NULL);
}