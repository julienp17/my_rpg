/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** ingame_loop
*/

#include "game.h"

void ingame_loop(game_t *game, int delta_time)
{
    ingame_poll_events(game);
    ingame_update(game, delta_time);
    sfRenderWindow_clear(game->win, sfBlack);
    ingame_draw(game);
    sfRenderWindow_display(game->win);
}