/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Return an int vector with the sum of x and y
*/

#include "graphical_def.h"

v2i v2i_add(v2i vector1, v2i vector2)
{
    v2i sum_vector = v2i(0, 0);

    sum_vector.x = vector1.x + vector2.x;
    sum_vector.y = vector1.y + vector2.y;
    return (sum_vector);
}