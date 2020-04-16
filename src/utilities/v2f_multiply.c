/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Multiply x and y of v2f by multiplier
*/

#include "graphical_def.h"

void v2f_multiply(v2f *vector, float multiplier)
{
    vector->x *= multiplier;
    vector->y *= multiplier;
}