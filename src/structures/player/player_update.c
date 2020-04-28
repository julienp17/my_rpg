/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_update
*/

#include "player.h"

void player_update(player_t *player, map_t *map, float delta_time)
{
    animation_update(player, (void *)&player_update_animation, delta_time);
    if (player_can_move(player, map, delta_time))
        player_move(player, delta_time);
}