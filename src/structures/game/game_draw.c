/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw the game
*/

#include "game.h"

void game_draw(game_t *game)
{
    sfRenderWindow_clear(game->win, sfBlack);
    map_draw_layer(game->win, game->map, BOTTOM);
    player_draw(game->win, game->player);
    map_draw_layer(game->win, game->map, TOP);
    sfRenderWindow_display(game->win);
}