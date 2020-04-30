/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns the tile number of the tile facing the player
*/

#include "player.h"

v2i player_get_facing_tile(player_t *player)
{
    v2f player_pos = v2f(0.0, 0.0);
    v2i grid_pos = v2i(0, 0);
    v2i dir = v2i(0, 0);

    player_pos = sprite_get_center(player->sprite);
    grid_pos = v2f_to_grid(player_pos, TILE_SIZE);
    dir = get_dir_by_key(player->orientation);
    grid_pos = v2i_add(grid_pos, dir);
    return (grid_pos);
}