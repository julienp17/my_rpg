/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Multiply x and y of v2f by multiplier
*/

#include "graphical_def.h"

v2f v2f_multiply(v2f vector1, v2f vector2)
{
    v2f product_vector = v2f(0, 0);

    product_vector.x = vector1.x * vector2.x;
    product_vector.y = vector1.y * vector2.y;
    return (product_vector);
}