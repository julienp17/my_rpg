/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Launch the game
*/

#include <stdio.h>
#include "game.h"

int game_run(window_t *win)
{
    game_t *game = NULL;

    game = game_create(win);
    if (game == NULL)
        return (-1);
    if (game_load(game) == -1)
        return (-1);
    while (sfRenderWindow_isOpen(game->win))
        game_loop(game);
    return (0);
}