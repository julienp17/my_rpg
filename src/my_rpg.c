/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg main file
*/

#include "game.h"
#include "my_rpg.h"

static void game_loop(game_t *game);

int my_rpg(window_t *win)
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

static void game_loop(game_t *game)
{
    int delta_time = 0;

    game_poll_events(game);
    delta_time = sfTime_asMilliseconds(sfClock_restart(game->clock));
    game_update(game, delta_time);
    game_draw(game);
}