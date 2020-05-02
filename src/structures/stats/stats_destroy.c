/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** stats_destroy
*/

#include <stdlib.h>
#include "stats.h"

void stats_destroy(stats_t *stats)
{
    free(stats);
}