/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Move the player
*/

#include "my_rpg.h"
#include "player.h"

void player_move(player_t *player, float delta_time)
{
    v2f offset = v2f(0, 0);

    offset = player_get_move_offset(player, delta_time);
    sfSprite_move(player->sprite, offset);
}