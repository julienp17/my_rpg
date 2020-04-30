/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_dir_by_key
*/

#include "graphical_def.h"

v2i get_dir_by_key(sfKeyCode key)
{
    v2i dir = v2i(0.0, 0.0);

    dir =   (key == sfKeyUp)    ? v2i(0, -1) :
            (key == sfKeyDown)  ? v2i(0, 1)  :
            (key == sfKeyLeft)  ? v2i(-1, 0) :
            (key == sfKeyRight) ? v2i(1, 0)  :
            v2i(0, 0);
    return (dir);
}