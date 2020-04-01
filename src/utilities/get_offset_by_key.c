/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_offset_by_key
*/

#include "graphical_def.h"

v2f get_offset_by_key(sfKeyCode key)
{
    v2f offset;

    offset = (key == sfKeyUp)   ? v2f(0, -1) :
            (key == sfKeyDown)  ? v2f(0, 1)  :
            (key == sfKeyLeft)  ? v2f(-1, 0) :
            (key == sfKeyRight) ? v2f(1, 0)  :
            v2f(0, 0);
    return (offset);
}