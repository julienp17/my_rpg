/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_random
*/

#include <stdlib.h>
#include "graphical_def.h"

int rand_in_range(int min, int max)
{
    if (min > max)
        return (-1);
    return (rand() % (max - min) + min);
}