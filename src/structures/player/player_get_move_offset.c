/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_get_move_offset
*/

#include "my_rpg.h"
#include "player.h"

v2f player_get_move_offset(player_t *player, float delta_time)
{
    v2f dir = v2f(0.0, 0.0);
    v2f offset = v2f(0.0, 0.0);

    dir = get_offset_by_key(player->orientation);
    offset.x = dir.x * delta_time * player->move_speed;
    offset.y = dir.y * delta_time * player->move_speed;
    return (offset);
}