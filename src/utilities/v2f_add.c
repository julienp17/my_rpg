/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Return a float vector with the sum of x and y
*/

#include "graphical_def.h"

v2f v2f_add(v2f vector1, v2f vector2)
{
    v2f sum_vector = v2f(0, 0);

    sum_vector.x = vector1.x + vector2.x;
    sum_vector.y = vector1.y + vector2.y;
    return (sum_vector);
}