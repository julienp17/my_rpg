/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Move the player
*/

#include "player.h"

void player_move(player_t *player, v2f offset)
{
    offset.x *= 32;
    offset.y *= 32;
    sfSprite_move(player->sprite, offset);
}