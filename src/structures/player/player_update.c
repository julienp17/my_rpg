/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_update
*/

#include "player.h"
#include "my_rpg.h"

void player_update(player_t *player, map_t *map, int delta_time)
{
    animation_update(player, (void *)&player_update_animation, delta_time);
    if (player_can_move(player, map)) {
        player_move(player);
        game_handle_warps(map, player);
    }
}