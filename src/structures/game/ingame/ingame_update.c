/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_update
*/

#include "game.h"

void ingame_update(game_t *game, int delta_time)
{
    map_update(game->map, delta_time);
    player_update(game->player, game->map, delta_time);
    ingame_update_view(game);
}