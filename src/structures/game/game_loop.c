/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_loop
*/

#include "game.h"

void game_loop(game_t *game)
{
    float delta_time = 0;

    game_poll_events(game);
    delta_time = sfTime_asSeconds(sfClock_restart(game->clock));
    game_update(game, delta_time);
    game_draw(game);
}