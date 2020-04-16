/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Multiply every field of a float rect by a given number
*/

#include "graphical_def.h"

void frect_multiply(frect *rect, float multiplier)
{
    rect->left *= multiplier;
    rect->top *= multiplier;
    rect->width *= multiplier;
    rect->height *= multiplier;
}