/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroys a game structure
*/

#include "game.h"

void game_destroy(game_t *game)
{
    sfRenderWindow_destroy(game->win);
    player_destroy(game->player);
    map_destroy(game->map);
    assets_destroy(game->assets);
}