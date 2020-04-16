/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroys a game structure
*/

#include "game.h"

void game_destroy(game_t *game)
{
    player_destroy(game->player);
    map_destroy(game->map);
    sfView_destroy(game->view);
    sfClock_destroy(game->clock);
    assets_destroy(game->assets);
}