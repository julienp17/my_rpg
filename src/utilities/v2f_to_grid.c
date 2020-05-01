/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** v2i_to_grid
*/

#include "map.h"

v2i v2f_to_grid(v2f vector)
{
    v2i grid_pos = v2i(0, 0);

    grid_pos.x = vector.x / TILE_SIZE;
    grid_pos.y = vector.y / TILE_SIZE;
    return (grid_pos);
}