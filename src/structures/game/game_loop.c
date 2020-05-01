/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_loop
*/

#include "game.h"
#include "pause_menu.h"

void game_loop(game_t *game)
{
    int delta_time = 0;

    delta_time = sfTime_asMilliseconds(sfClock_restart(game->clock));
    if (game->state == PAUSE_MENU)
        pause_menu_run(game);
    else if (game->state == INGAME)
        ingame_loop(game, delta_time);
}