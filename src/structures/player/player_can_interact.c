/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns true if the player can interact with something in the map
*/

#include "player.h"

static bool is_out_of_bounds(v2i grid_pos, map_t *map);

bool player_can_interact(player_t *player, map_t *map)
{
    v2f player_pos = v2f(0.0, 0.0);
    v2i grid_pos = v2i(0, 0);
    v2i dir = v2i(0, 0);
    npc_t *npc = NULL;

    dir = get_dir_by_key(player->orientation);
    player_pos = sfSprite_getPosition(player->sprite);
    grid_pos = v2f_to_grid(player_pos, TILE_SIZE);
    grid_pos = v2i_add(grid_pos, dir);
    if (is_out_of_bounds(grid_pos, map))
        return (false);
    npc = map_get_npc_from_grid(map, grid_pos);
    return (npc != NULL);
}

static bool is_out_of_bounds(v2i grid_pos, map_t *map)
{
    v2i map_grid_size = v2i(0, 0);

    map_grid_size = v2f_to_grid(map->size, TILE_SIZE);
    return (
        grid_pos.x < 0
        || grid_pos.y < 0
        || grid_pos.x > map_grid_size.x
        || grid_pos.y > map_grid_size.y
    );
}