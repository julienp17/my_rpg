/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_update
*/

#include "game.h"
#include "my_rpg.h"

void game_update(game_t *game, int delta_time)
{
    player_update(game->player, delta_time);
    map_update(game->map, delta_time);
    game_update_view(game);
}