/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_handle_wrap
*/

#include <stdlib.h>
#include "player.h"
#include "my.h"

void game_handle_wrap(map_t *map, player_t *player)
{
    warp_t *warp = NULL;
    v2f pos = v2f(0, 0);

    pos = sfSprite_getPosition(player->sprite);
    for (uint i = 0 ; map->warps[i] && warp == NULL ; i++)
        if (sfFloatRect_contains(&(map->warps[i]->zone), pos.x, pos.y))
            warp = map->warps[i];
    if (warp == NULL)
        return;
    if (map_load(map, warp->map_name) == EXIT_FAILURE) {
        my_puterr(warp->map_name);
        my_puterr(" : couldn't load map.\n");
    }
    sfSprite_setPosition(player->sprite, warp->dest);
}