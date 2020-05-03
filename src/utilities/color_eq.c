/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** color_eq
*/

#include "graphical_def.h"

bool color_eq(color_t color1, color_t color2)
{
    return (
        color1.r == color2.r
        && color1.g == color2.g
        && color1.b == color2.b
    );
}