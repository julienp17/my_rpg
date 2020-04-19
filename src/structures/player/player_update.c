/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_update
*/

#include "player.h"

void player_update(player_t *player, int delta_time)
{
    animation_update(player, (void *)&player_update_animation, delta_time);
}