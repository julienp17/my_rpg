/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** v2i_eq
*/

#include <stdbool.h>
#include "graphical_def.h"

bool v2i_eq(v2i vector1, v2i vector2)
{
    return (vector1.x == vector2.x && vector1.y == vector2.y);
}