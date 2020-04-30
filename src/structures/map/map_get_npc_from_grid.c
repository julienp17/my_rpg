/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Return an npc from a map based on its grid position
*/

#include "map.h"

npc_t *map_get_npc_from_grid(map_t *map, v2i grid_pos)
{
    npc_t *npc = NULL;
    v2f npc_pos = v2f(0.0, 0.0);
    v2i npc_grid_pos = v2i(0, 0);

    for (uint i = 0 ; map->npcs[i] && npc == NULL ; i++) {
        npc_pos = sfSprite_getPosition(map->npcs[i]->sprite);
        npc_grid_pos = v2f_to_grid(npc_pos);
        if (v2i_eq(npc_grid_pos, grid_pos))
            npc = map->npcs[i];
    }
    return (npc);
}