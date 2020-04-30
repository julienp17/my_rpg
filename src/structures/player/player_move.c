/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Move the player
*/

#include "player.h"

void player_move(player_t *player)
{
    v2f offset = v2f(0.0, 0.0);

    offset = player_get_move_offset(player);
    sfSprite_move(player->sprite, offset);
}