/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_get_move_offset
*/

#include "player.h"

v2f player_get_move_offset(player_t *player, int delta_time)
{
    v2f offset = v2f(0.0, 0.0);
    v2i dir = v2i(0, 0);

    dir = get_dir_by_key(player->orientation);
    offset.x = dir.x * player->move_speed * delta_time;
    offset.y = dir.y * player->move_speed * delta_time;
    return (offset);
}