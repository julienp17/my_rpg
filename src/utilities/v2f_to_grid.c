/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** v2i_to_grid
*/

#include "graphical_def.h"

v2i v2f_to_grid(v2f vector, int tile_size)
{
    v2i grid_pos = v2i(0, 0);

    grid_pos.x = vector.x / tile_size;
    grid_pos.y = vector.y / tile_size;
    return (grid_pos);
}