/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns true if the player is moving, false otherwise
*/

#include "player.h"

bool player_is_moving(player_t *player)
{
    return (player->move_speed > 0.0f);
}