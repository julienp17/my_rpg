/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Checks if the player in in a wrap, and change map if he is
*/

#include <stdlib.h>
#include "map.h"
#include "player.h"

int ingame_handle_warps(map_t *map, player_t *player)
{
    warp_t *warp = NULL;
    v2f pos = v2f(0, 0);

    pos = sfSprite_getPosition(player->sprite);
    for (uint i = 0 ; map->warps[i] && warp == NULL ; i++)
        if (sfFloatRect_contains(&(map->warps[i]->zone), pos.x, pos.y))
            warp = map->warps[i];
    if (warp) {
        sfSprite_setPosition(player->sprite, warp->dest);
        if (map_load(map, warp->map_name) == EXIT_FAILURE)
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}