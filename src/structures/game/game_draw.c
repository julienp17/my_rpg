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
    map_draw(game->win, game->map);
    sfRenderWindow_display(game->win);
}